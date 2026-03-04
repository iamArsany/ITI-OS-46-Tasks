<?php

$user_id = $_GET['id'];

$host = "localhost";
$user = "root";
$pass = "1234";
$db   = "php";

try {
    $conn = new PDO("mysql:host=$host;dbname=$db", $user, $pass);

    $sql = "DELETE FROM users WHERE id = ?";

    $stmt = $conn->prepare($sql);

    $stmt->execute([$user_id]);

    header("Location: redirection.php");
    exit();
} catch (PDOException $e) {
    echo "Delete failed: " . $e->getMessage();
}

$conn = null;
