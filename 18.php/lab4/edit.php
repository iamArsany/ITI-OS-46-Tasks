<?php
$user_id = $_GET['id'];
$host = "localhost";
$user = "root";
$pass = "1234";
$db   = "php";

try {
    $conn = new PDO("mysql:host=$host;dbname=$db", $user, $pass);
    $conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

    $stmt = $conn->prepare("SELECT * FROM users WHERE id = ?");
    $stmt->execute([$user_id]);
    $user_data = $stmt->fetch(PDO::FETCH_ASSOC);
    $saved_skills = explode(", ", $user_data['skills']);
} catch (PDOException $e) {
    die("Error: " . $e->getMessage());
}
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Edit User</title>
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0/dist/css/bootstrap.min.css" rel="stylesheet">
</head>
<body class="bg-light">

    <div class="container mt-5 mb-5">
        <div class="card p-4 shadow-sm" style="max-width: 650px; margin: auto;">
            <h2 class="mb-4 text-center border-bottom pb-2">Edit User Profile</h2>
            
            <form action="update.php" method="POST" enctype="multipart/form-data">
                <input type="hidden" name="id" value="<?php echo $user_data['id']; ?>">

                <div class="row mb-3">
                    <div class="col-md-6">
                        <label class="form-label">First Name</label>
                        <input type="text" name="fname" class="form-control" value="<?php echo $user_data['fname']; ?>">
                    </div>
                    <div class="col-md-6">
                        <label class="form-label">Last Name</label>
                        <input type="text" name="lname" class="form-control" value="<?php echo $user_data['lname']; ?>">
                    </div>
                </div>

                <div class="mb-3">
                    <label class="form-label">Address</label>
                    <textarea name="address" class="form-control" rows="3"><?php echo $user_data['address']; ?></textarea>
                </div>

                <div class="mb-3">
                    <label class="form-label">Country</label>
                    <select name="country" class="form-select">
                        <option value="Egypt" <?php if ($user_data['country'] == 'Egypt') {
                            echo 'selected';
                                              } ?>>Egypt</option>
                        <option value="USA" <?php if ($user_data['country'] == 'USA') {
                            echo 'selected';
                                            } ?>>USA</option>
                        <option value="UK" <?php if ($user_data['country'] == 'UK') {
                            echo 'selected';
                                           } ?>>UK</option>
                    </select>
                </div>

                <div class="mb-3">
                    <label class="form-label d-block">Gender</label>
                    <div class="form-check form-check-inline">
                        <input class="form-check-input" type="radio" name="gender" value="Male" <?php if ($user_data['gender'] == 'Male') {
                            echo 'checked';
                                                                                                } ?>>
                        <label class="form-check-label">Male</label>
                    </div>
                    <div class="form-check form-check-inline">
                        <input class="form-check-input" type="radio" name="gender" value="Female" <?php if ($user_data['gender'] == 'Female') {
                            echo 'checked';
                                                                                                  } ?>>
                        <label class="form-check-label">Female</label>
                    </div>
                </div>

                <div class="mb-3">
                    <label class="form-label d-block">Skills</label>
                    <div class="row">
                        <div class="col-6">
                            <div class="form-check">
                                <input class="form-check-input" type="checkbox" name="skills[]" value="PHP" <?php if (in_array("PHP", $saved_skills)) {
                                    echo "checked";
                                                                                                            } ?>>
                                <label class="form-check-label">PHP</label>
                            </div>
                            <div class="form-check">
                                <input class="form-check-input" type="checkbox" name="skills[]" value="J2SE" <?php if (in_array("J2SE", $saved_skills)) {
                                    echo "checked";
                                                                                                             } ?>>
                                <label class="form-check-label">J2SE</label>
                            </div>
                        </div>
                        <div class="col-6">
                            <div class="form-check">
                                <input class="form-check-input" type="checkbox" name="skills[]" value="MySQL" <?php if (in_array("MySQL", $saved_skills)) {
                                    echo "checked";
                                                                                                              } ?>>
                                <label class="form-check-label">MySQL</label>
                            </div>
                            <div class="form-check">
                                <input class="form-check-input" type="checkbox" name="skills[]" value="PostgreSQL" <?php if (in_array("PostgreSQL", $saved_skills)) {
                                    echo "checked";
                                                                                                                   } ?>>
                                <label class="form-check-label">PostgreSQL</label>
                            </div>
                        </div>
                    </div>
                </div>

                <div class="mb-3">
                    <label class="form-label">Username</label>
                    <input type="text" name="username" class="form-control" value="<?php echo $user_data['username']; ?>">
                </div>

                <div class="mb-3">
                    <label class="form-label">Password</label>
                    <input type="password" name="password" class="form-control" value="<?php echo $user_data['password']; ?>">
                </div>

                <div class="mb-3">
                    <label class="form-label">Profile Image</label>
                    <div class="mb-2">
                        <img src="uploads/<?php echo $user_data['image']; ?>" width="100" class="img-thumbnail">
                    </div>
                    <input type="file" name="profile_image" class="form-control" accept="image/*">
                    <input type="hidden" name="old_image" value="<?php echo $user_data['image']; ?>">
                </div>

                <div class="mt-4">
                    <button type="submit" class="btn btn-success w-100">Update Now</button>
                    <a href="redirection.php" class="btn btn-link w-100 mt-2 text-decoration-none">Cancel</a>
                </div>
            </form>
        </div>
    </div>

</body>
</html>
