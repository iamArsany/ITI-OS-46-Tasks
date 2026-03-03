<?php
$fname = $_POST['fname'];
$lname = $_POST['lname'];
$address = $_POST['address'];
$gender = $_POST['gender'];
$dept = $_POST['dept'];
$captcha_input = $_POST['captcha_input'];
$captcha_real = $_POST['captcha_real'];

$prefix = ($gender == "Male") ? "Mr." : "Miss";

$skills_string = "";

if (isset($_POST['skills'])) {
    $all_skills = $_POST['skills']; 

    foreach ($all_skills as $single_skill) {
        $skills_string = $skills_string . $single_skill . " ";
    }

} else {
    $skills_string = "No skills selected";
}

echo "<p><strong>Your Skills:</strong> " . $skills_string . "</p>";?>

<!DOCTYPE html>
<html>
<head>
    <title>Review Page</title>
</head>
<body>

    <h2>Review</h2>

    <?php

if ($captcha_input == $captcha_real) {
    echo "<h1>Review</h1>";
    echo "<p>Thanks " . $prefix . " " . $fname . " " . $lname . "</p>";

    echo "<h3>Please Review Your Information:</h3>";

    echo "<p><strong>Name:</strong> " . $fname . " " . $lname . "</p>";
    echo "<p><strong>Address:</strong> " . $address . "</p>";
    echo "<p><strong>Your Skills:</strong> " . $skills . "</p>";
    echo "<p><strong>Department:</strong> " . $dept . "</p>";

} else {
    echo "<h3 style='color: red;'>Verification Failed!</h3>";
    echo "<p>The code you entered was incorrect.</p>";
    echo "<a href='registration.php'>Go Back and Try Again</a>";
}
?>
</body>
</html>
