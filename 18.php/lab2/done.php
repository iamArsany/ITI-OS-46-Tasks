<?php
$fname = $_POST['fname'];
$lname = $_POST['lname'];
$address = $_POST['address'];
$gender = $_POST['gender'];
$country = $_POST['country'];
$dept = $_POST['dept'];
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

    $data_to_save = $fname . "," . $lname . "," . $address . "," . $gender . "," .  $skills_string . "," . $dept . "\n";
    file_put_contents("data.txt", $data_to_save, FILE_APPEND);

    echo "<h1>Success!</h1>";
    echo "<p>Data has been saved to data.txt</p>";
    echo "<a href='data.txt'>View Saved Data</a>";

} else {
    echo "<h3 style='color: red;'>Verification Failed!</h3>";
    echo "<a href='registration.php'>Go Back and Try Again</a>";
}
?>
