<?php

$user_id = $_GET['id'];

$host = "localhost";
$user = "root";
$pass = "1234";
$db   = "php";

try {
    $conn = new PDO("mysql:host=$host;dbname=$db", $user, $pass);
    $conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

    $stmt = $conn->prepare("SELECT image FROM users WHERE id = ?");
    $stmt->execute([$user_id]);
    $user_data = $stmt->fetch(PDO::FETCH_ASSOC);

    if ($user_data) {
        $image_path = "uploads/" . $user_data['image'];
        if (file_exists($image_path) && !empty($user_data['image'])) {
            unlink($image_path);
        }
    }

    $sql = "DELETE FROM users WHERE id = ?";
    $stmt = $conn->prepare($sql);
    $stmt->execute([$user_id]);

    header("Location: redirection.php");
    exit();
} catch (PDOException $e) {
    echo "Delete failed: " . $e->getMessage();
}

$conn = null;
