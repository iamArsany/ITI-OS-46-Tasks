<?php

$fname    = $_POST['fname'] ?? '';
$lname    = $_POST['lname'] ?? '';
$address  = $_POST['address'] ?? '';
$country  = $_POST['country'] ?? '';
$gender   = $_POST['gender'] ?? '';
$skills_array = $_POST['skills'] ?? [];
$username = $_POST['username'] ?? '';
$password = $_POST['password'] ?? '';
$dept     = $_POST['dept'] ?? '';

$image_file = $_FILES['profile_image'] ?? null;

$errors = [];


if (empty($fname)) {
    $errors[] = "First Name is required.";
}
if (empty($lname)) {
    $errors[] = "Last Name is required.";
}
if (empty($address)) {
    $errors[] = "Address is required.";
}
if (empty($country)) {
    $errors[] = "Country is required.";
}
if (empty($gender)) {
    $errors[] = "Gender is required.";
}
if (empty($username)) {
    $errors[] = "Username is required.";
}

if (!empty($fname) && !preg_match("/^[a-zA-Z\s]+$/", $fname)) {
    $errors[] = "First Name cannot contain numbers.";
}
if (!empty($lname) && !preg_match("/^[a-zA-Z\s]+$/", $lname)) {
    $errors[] = "Last Name cannot contain numbers.";
}

if (empty($skills_array)) {
    $errors[] = "Please select at least one skill.";
}

if (!preg_match("/^[a-z0-9_]{8}$/", $password)) {
    $errors[] = "Password must be exactly 8 characters (lowercase, numbers, and underscores only).";
}

if (!$image_file || $image_file['error'] == 4) {
    $errors[] = "Image is required.";
} else {
    $allowed_exts = ['jpg', 'jpeg', 'png'];
    $file_ext = strtolower(pathinfo($image_file['name'], PATHINFO_EXTENSION));
    $file_size = $image_file['size'];

    if (!in_array($file_ext, $allowed_exts)) {
        $errors[] = "Invalid format. Only JPG and PNG allowed.";
    }
    if ($file_size > 2 * 1024 * 1024) { // 2MB
        $errors[] = "File size must be less than 2MB.";
    }
}


if (!empty($errors)) {
    echo '<link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0/dist/css/bootstrap.min.css" rel="stylesheet">';
    echo "<div class='container mt-5'><div class='alert alert-danger'><h3>Validation Errors:</h3><ul>";
    foreach ($errors as $error) {
        echo "<li>$error</li>";
    }
    echo "</ul><a href='javascript:history.back()' class='btn btn-secondary'>Go Back</a></div></div>";
    exit;
}

$folder = "uploads/";
$image_name = time() . "_" . basename($image_file["name"]);
$target_path = $folder . $image_name;

if (!move_uploaded_file($image_file["tmp_name"], $target_path)) {
    die("Error: Failed to upload the image to the folder.");
}

$skills_string = implode(", ", $skills_array);
$host = "localhost";
$user = "root";
$pass = "1234";
$db   = "php";

try {
    $conn = new PDO("mysql:host=$host;dbname=$db", $user, $pass);
    $conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

    // Added 'image' column and one extra '?' at the end
    $sql = "INSERT INTO users (fname, lname, address, country, gender, skills, dept, username, password, image) 
            VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";

    $stmt = $conn->prepare($sql);
    $stmt->execute([
        $fname,
        $lname,
        $address,
        $country,
        $gender,
        $skills_string,
        $dept,
        $username,
        $password,
        $image_name
    ]);

    echo '<link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0/dist/css/bootstrap.min.css" rel="stylesheet">';
    echo "<div class='container mt-5 text-center'>";
    echo "<div class='card p-5 shadow-sm'>";
    echo "<h1 class='text-success'>Registration Done!</h1>";
    echo "<p class='lead'>Thanks <strong>" . htmlspecialchars($fname) . "</strong>, your account and image were saved.</p>";
    echo "<a href='redirection.php' class='btn btn-primary mt-3'>Show Users</a>";
    echo "</div></div>";
} catch (PDOException $e) {
    echo "Database Error: " . $e->getMessage();
}

$conn = null;
