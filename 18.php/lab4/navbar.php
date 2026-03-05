<?php
if (session_status() === PHP_SESSION_NONE) {
    session_start();
}
?>

<nav class="navbar navbar-expand-lg navbar-dark bg-dark mb-4">

<div class="container">

<a class="navbar-brand" href="redirection.php">
User System
</a>

<div class="collapse navbar-collapse">

<ul class="navbar-nav ms-auto align-items-center">

<?php if (isset($_SESSION['user_name'])) : ?>
<li class="nav-item">
<span class="nav-link text-light">
Welcome, <strong><?php echo $_SESSION['user_name']; ?></strong>
</span>
</li>

<li class="nav-item">
<a class="btn btn-outline-danger btn-sm ms-2" href="logout.php">
Logout
</a>
</li>

<?php else : ?>
<li class="nav-item">
<a class="nav-link" href="login.php">Login</a>
</li>

<?php endif; ?>

</ul>

</div>
</div>
</nav>
