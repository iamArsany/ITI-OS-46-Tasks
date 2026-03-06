<?php

include 'navbar.php';
require_once 'Database.php';
use Classes\Database;

$id        = $_POST['id'];
$fname     = $_POST['fname'];
$lname     = $_POST['lname'];
$address   = $_POST['address'];
$country   = $_POST['country'];
$gender    = $_POST['gender'];
$skills    = implode(", ", $_POST['skills'] ?? []);
$username  = $_POST['username'];
$password  = $_POST['password'];
$old_image = $_POST['old_image'];

$image_name = $old_image;

if (isset($_FILES['profile_image']) && $_FILES['profile_image']['error'] == 0) {
    $folder     = "uploads/";
    $image_name = time() . "_" . $_FILES['profile_image']['name'];
    if (move_uploaded_file($_FILES['profile_image']['tmp_name'], $folder . $image_name)) {
        if (file_exists($folder . $old_image)) {
            unlink($folder . $old_image);
        }
    }
}

$db = Database::getInstance();
$db->update("users", [
    "fname"    => $fname,
    "lname"    => $lname,
    "address"  => $address,
    "country"  => $country,
    "gender"   => $gender,
    "skills"   => $skills,
    "username" => $username,
    "password" => $password,
    "image"    => $image_name
], "id", $id);

header("Location: redirection.php");
