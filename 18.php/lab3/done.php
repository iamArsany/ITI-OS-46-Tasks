<?php

$fname    = $_POST['fname'];
$lname    = $_POST['lname'];
$address  = $_POST['address'];
$country  = $_POST['country'];
$gender   = $_POST['gender'];
$skills_array = $_POST['skills'] ?? [];
$skills_string = implode(", ", $skills_array);
$username = $_POST['username'];
$password = $_POST['password'];
$dept     = $_POST['dept'];

$host = "localhost";
$user = "root";
$pass = "1234";
$db   = "php";

try {
    $conn = new PDO("mysql:host=$host;dbname=$db", $user, $pass);

    $sql = "INSERT INTO users (fname, lname, address, country, gender, skills, dept, username, password) 
        VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?)";

    $stmt = $conn->prepare($sql);

    $stmt->execute([
      $fname
      , $lname
      , $address
      , $country
      ,$gender
      ,$skills_string
      , $dept
      , $username
      , $password]);

    echo '<link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0/dist/css/bootstrap.min.css" rel="stylesheet">';
    echo "<h1>Registration Done!</h1>";
    echo "Thanks " . $fname . ", your account is created.";
    echo "<a href='redirection.php' class='m-3 btn btn-primary'>Show Users</a>";
} catch (PDOException $e) {
    echo "Error: " . $e->getMessage();
}

$conn = null;
