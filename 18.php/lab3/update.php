<?php

$id       = $_POST['id'];
$fname    = $_POST['fname'];
$lname    = $_POST['lname'];
$address  = $_POST['address'];
$country  = $_POST['country'];
$gender   = $_POST['gender'];
$skills_string = implode(", ", $_POST['skills'] ?? []);
$username = $_POST['username'];
$password = $_POST['password'];

$host = "localhost";
$user = "root";
$pass = "1234";
$db   = "php";

try {
    $conn = new PDO("mysql:host=$host;dbname=$db", $user, $pass);

    $sql = "UPDATE users SET 
            fname = ?, 
            lname = ?, 
            address = ?, 
            country = ?, 
            gender = ?,
            skills = ?, 
            username = ?, 
            password = ? 
            WHERE id = ?";

    $stmt = $conn->prepare($sql);

    $stmt->execute([$fname, $lname, $address, $country, $gender,$skills_string, $username, $password, $id]);

    header("Location: redirection.php");
    exit();
} catch (PDOException $e) {
    echo "Update failed: " . $e->getMessage();
}
