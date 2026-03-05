<?php
include 'navbar.php'; ?>

<?php

$id       = $_POST['id'];
$fname    = $_POST['fname'];
$lname    = $_POST['lname'];
$address  = $_POST['address'];
$country  = $_POST['country'];
$gender   = $_POST['gender'];
$skills   = implode(", ", $_POST['skills'] ?? []);
$username = $_POST['username'];
$password = $_POST['password'];
$old_image = $_POST['old_image'];

$image_name = $old_image;

if (isset($_FILES['profile_image']) && $_FILES['profile_image']['error'] == 0) {
    $folder = "uploads/";
    $image_name = time() . "_" . $_FILES['profile_image']['name'];

    if (move_uploaded_file($_FILES['profile_image']['tmp_name'], $folder . $image_name)) {
        if (file_exists($folder . $old_image)) {
            unlink($folder . $old_image);
        }
    }
}

$host = "localhost";
$user = "root";
$pass = "1234";
$db   = "php";

try {
    $conn = new PDO("mysql:host=$host;dbname=$db", $user, $pass);
    $sql = "UPDATE users SET fname=?, lname=?, address=?, country=?, gender=?, skills=?, username=?, password=?, image=? WHERE id=?";
    $stmt = $conn->prepare($sql);
    $stmt->execute([$fname, $lname, $address, $country, $gender, $skills, $username, $password, $image_name, $id]);

    header("Location: redirection.php");
} catch (PDOException $e) {
    echo "Error: " . $e->getMessage();
}
