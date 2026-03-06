<?php
session_start();
require_once 'Database.php';
use Classes\Database;

$errors = [];

if ($_SERVER['REQUEST_METHOD'] == 'POST') {
    $username = $_POST['username'] ?? '';
    $password = $_POST['password'] ?? '';

    if (empty($username)) {
        $errors[] = "Username is required.";
    }
    if (empty($password)) {
        $errors[] = "Password is required.";
    }

    if (empty($errors)) {
        $db = Database::getInstance();
        $user_data = $db->getOne("users", "username", $username);

        if ($user_data && $password === $user_data['password']) {
            $_SESSION['user_id']   = $user_data['id'];
            $_SESSION['user_name'] = $user_data['username'];
            header("Location: view.php?id=" . $user_data['id']);
            exit();
        } else {
            $errors[] = "Invalid username or password.";
        }
    }
}
?>
<!DOCTYPE html>
<html lang="en">
<head>
<meta charset="UTF-8">
<title>Login</title>
<link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0/dist/css/bootstrap.min.css" rel="stylesheet">
</head>
<body class="bg-light">
<div class="container mt-5">
<div class="card shadow-sm mx-auto" style="max-width: 400px;">
<div class="card-header bg-primary text-white text-center">
<h4 class="mb-0">Login</h4>
</div>
<div class="card-body">
<?php if (!empty($errors)) : ?>
<div class="alert alert-danger">
<ul class="mb-0">
    <?php foreach ($errors as $error) : ?>
<li><?php echo $error; ?></li>
    <?php endforeach; ?>
</ul>
</div>
<?php endif; ?>
<form action="login.php" method="POST">
<div class="mb-3">
<label class="form-label">Username</label>
<input type="text" name="username" class="form-control" required>
</div>
<div class="mb-3">
<label class="form-label">Password</label>
<input type="password" name="password" class="form-control" required>
</div>
<button type="submit" class="btn btn-primary w-100">Sign In</button>
</form>
</div>
<div class="card-footer text-center">
<small>New user? <a href="registration.php">Register here</a></small>
</div>
</div>
</div>
</body>
</html>
