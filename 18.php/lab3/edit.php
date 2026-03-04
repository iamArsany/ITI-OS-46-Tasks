<?php
$user_id = $_GET['id']; // Get ID from the URL

$host = "localhost";
$user = "root";
$pass = "1234";
$db   = "php";

$conn = new PDO("mysql:host=$host;dbname=$db", $user, $pass);

// Get current data for this user
$stmt = $conn->prepare("SELECT * FROM users WHERE id = ?");
$stmt->execute([$user_id]);
$user_data = $stmt->fetch(PDO::FETCH_ASSOC);
$saved_skills = explode(", ", $user_data['skills']);
?>

<!DOCTYPE html>
<html>
<head><title>Edit User</title></head>
<body>
    <h2>Edit User</h2>
    <form action="update.php" method="POST">
        <input type="hidden" name="id" value="<?php echo $user_data['id']; ?>">

        First Name: <input type="text" name="fname" value="<?php echo $user_data['fname']; ?>"><br><br>
        Last Name: <input type="text" name="lname" value="<?php echo $user_data['lname']; ?>"><br><br>
        Address: <br>
        <textarea name="address"><?php echo $user_data['address']; ?></textarea><br><br>
        
        Country: 
        <select name="country">
            <option value="Egypt" <?php if ($user_data['country'] == 'Egypt') {
                echo 'selected';
                                  } ?>>Egypt</option>
            <option value="USA" <?php if ($user_data['country'] == 'USA') {
                echo 'selected';
                                } ?>>USA</option>
            <option value="UK" <?php if ($user_data['country'] == 'UK') {
                echo 'selected';
                               } ?>>UK</option>
        </select><br><br>

        Gender: 
        <input type="radio" name="gender" value="Male" <?php if ($user_data['gender'] == 'Male') {
            echo 'checked';
                                                       } ?>> Male
        <input type="radio" name="gender" value="Female" <?php if ($user_data['gender'] == 'Female') {
            echo 'checked';
                                                         } ?>> Female <br><br>

Skills: <br>
<input type="checkbox" name="skills[]" value="PHP" <?php if (in_array("PHP", $saved_skills)) {
    echo "checked";
                                                   } ?>> PHP
<input type="checkbox" name="skills[]" value="J2SE" <?php if (in_array("J2SE", $saved_skills)) {
    echo "checked";
                                                    } ?>> J2SE <br>
<input type="checkbox" name="skills[]" value="MySQL" <?php if (in_array("MySQL", $saved_skills)) {
    echo "checked";
                                                     } ?>> MySQL
<input type="checkbox" name="skills[]" value="PostgreSQL" <?php if (in_array("PostgreSQL", $saved_skills)) {
    echo "checked";
                                                          } ?>> PostgreSQL <br><br>

        Username: <input type="text" name="username" value="<?php echo $user_data['username']; ?>"><br><br>
        Password: <input type="password" name="password" value="<?php echo $user_data['password']; ?>"><br><br>

        <input type="submit" value="Update Now">
    </form>
</body>
</html>
