<?php
$fname = $_POST['fname'];
$lname = $_POST['lname'];
$address = $_POST['address'];
$gender = $_POST['gender'];
$country = $_POST['country'];
$dept = $_POST['dept'];
$username=$_POST['username'];
$password=$_POST['password'];
$captcha_input = $_POST['captcha_input'];
$captcha_real = $_POST['captcha_real'];

$skills_string = "";
if (isset($_POST['skills'])) {
    foreach ($_POST['skills'] as $single_skill) {
        $skills_string = $skills_string . $single_skill . " ";
    }
} else {
    $skills_string = "None";
}

if ($captcha_input == $captcha_real) {
    $data_to_save = $fname . "," . $lname . "," . $address . "," . $country . "," . $gender . "," . $skills_string . "," . $dept . "," . $username . "," . $password . "\n";
    file_put_contents("data.txt", $data_to_save, FILE_APPEND);

    header("Location: redirection.php");
    exit();
} else {
    echo "<h3 style='color: red;'>Verification Failed!</h3>";
    echo "<a href='registration.php'>Go Back and Try Again</a>";
}
?>
