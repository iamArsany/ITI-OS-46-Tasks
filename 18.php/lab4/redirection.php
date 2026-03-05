<?php include 'navbar.php'; ?>
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
    <?php

    $host = "localhost";
    $user = "root";
    $pass = "1234";
    $db   = "php";

    try {
        $conn = new PDO("mysql:host=$host;dbname=$db", $user, $pass);

        $sql = "SELECT * FROM users";
        $stmt = $conn->query($sql);

        while ($row = $stmt->fetch(PDO::FETCH_ASSOC)) {
            echo "<tr>";
            echo "<td>" . $row['id'] . "</td>";
            echo "<td>" . $row['fname'] . "</td>";
            echo "<td>" . $row['lname'] . "</td>";
            echo "<td>" . $row['address'] . "</td>";
            echo "<td>" . $row['country'] . "</td>";
            echo "<td>" . $row['gender'] . "</td>";
            echo "<td>" . $row['dept'] . "</td>";
            echo "<td>" . $row['skills'] . "</td>";
            echo "<td>" . $row['username'] . "</td>";

            echo "<td>
                    <a href='view.php?id=" . $row['id'] . "' class='btn btn-sm btn-primary'>View</a>
                    <a href='edit.php?id=" . $row['id'] . "' class='btn btn-sm btn-warning'>Edit</a>
                    <a href='delete.php?id=" . $row['id'] . "' class='btn btn-sm btn-danger' onclick='return confirm(\"Are you sure?\")'>Delete</a>
                  </td>";
            echo "</tr>";
        }
    } catch (PDOException $e) {
        echo "Error: " . $e->getMessage();
    }
    ?>
    </tbody>
    </table>
    
    <br>
    <a href="registration.php" class="btn btn-success">Add New User</a>
</body>
</html>
