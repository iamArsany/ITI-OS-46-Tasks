<?php

require_once 'Database.php';
use Classes\Database;

$db = Database::getInstance();
$user_id = $_GET['id'];

$user_data = $db->getOne("users", "id", $user_id);

if ($user_data) {
    $image_path = "uploads/" . $user_data['image'];
    if (file_exists($image_path) && !empty($user_data['image'])) {
        unlink($image_path);
    }
}

$db->delete("users", "id", $user_id);
header("Location: redirection.php");
exit();
