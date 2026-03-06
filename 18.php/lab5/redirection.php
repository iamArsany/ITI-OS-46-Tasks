<?php
require_once 'Database.php';
use Classes\Database;

include 'navbar.php';
$db = Database::getInstance();
$users = $db->getAll("users");
?>
<html>
<link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0/dist/css/bootstrap.min.css" rel="stylesheet">
<head><title>All Users</title></head>
<body class="container mt-4">
    <h2>User Data List</h2>
    <table class="table table-bordered table-striped">
    <thead class="table-dark">
        <tr>
            <th>ID</th> <th>First Name</th>
            <th>Last Name</th>
            <th>Address</th>
            <th>Country</th> 
            <th>Gender</th>
            <th>Department</th>
            <th>Skills</th>
            <th>Username</th>
            <th>Actions</th>
        </tr>
    </thead>
    <tbody>
    <?php foreach ($users as $row) : ?>
        <tr>
            <td><?php echo $row['id']; ?></td>
            <td><?php echo $row['fname']; ?></td>
            <td><?php echo $row['lname']; ?></td>
            <td><?php echo $row['address']; ?></td>
            <td><?php echo $row['country']; ?></td>
            <td><?php echo $row['gender']; ?></td>
            <td><?php echo $row['dept']; ?></td>
            <td><?php echo $row['skills']; ?></td>
            <td><?php echo $row['username']; ?></td>
            <td>
                <a href="view.php?id=<?php echo $row['id']; ?>" class="btn btn-sm btn-primary">View</a>
                <a href="edit.php?id=<?php echo $row['id']; ?>" class="btn btn-sm btn-warning">Edit</a>
                <a href="delete.php?id=<?php echo $row['id']; ?>" class="btn btn-sm btn-danger" onclick="return confirm('Are you sure?')">Delete</a>
            </td>
        </tr>
    <?php endforeach; ?>
    </tbody>
    </table>
    
    <br>
    <a href="registration.php" class="btn btn-success">Add New User</a>
</body>
</html>
