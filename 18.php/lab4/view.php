<?php include 'navbar.php'; ?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>View User Details</title>
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0/dist/css/bootstrap.min.css" rel="stylesheet">
    <style>
        .profile-view-img {
            width: 150px;
            height: 150px;
            object-fit: cover;
            border-radius: 50%;
            border: 5px solid #fff;
            box-shadow: 0px 4px 10px rgba(0,0,0,0.1);
        }
        .no-img-view {
            width: 150px;
            height: 150px;
            background-color: black;
            border-radius: 50%;
            display: inline-block;
            margin: auto;
        }
    </style>
</head>
<body class="bg-light">

<div class="container mt-5">
    <div class="card shadow mx-auto" style="max-width: 600px;">
        <div class="card-header bg-primary text-white text-center">
            <h3 class="mb-0">User Profile</h3>
        </div>
        <div class="card-body">
            <?php
            if (isset($_GET['id'])) {
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

                    if ($user_data) {
                        // Display Profile Image at the top center
                        echo '<div class="text-center mb-4">';
                        if (!empty($user_data['image']) && file_exists("uploads/" . $user_data['image'])) {
                            echo "<img src='uploads/" . $user_data['image'] . "' class='profile-view-img' alt='Profile Photo'>";
                        } else {
                            echo "<div class='no-img-view'></div>";
                        }
                        echo '</div>';

                        // User Details Table
                        echo '<table class="table table-hover">';
                        echo "<tr><th>ID</th><td>" . $user_data['id'] . "</td></tr>";
                        echo "<tr><th>Full Name</th><td>" . $user_data['fname'] . " " . $user_data['lname'] . "</td></tr>";
                        echo "<tr><th>Username</th><td>" . $user_data['username'] . "</td></tr>";
                        echo "<tr><th>Email/Pass</th><td>" . $user_data['password'] . "</td></tr>";
                        echo "<tr><th>Address</th><td>" . $user_data['address'] . "</td></tr>";
                        echo "<tr><th>Country</th><td>" . $user_data['country'] . "</td></tr>";
                        echo "<tr><th>Gender</th><td>" . $user_data['gender'] . "</td></tr>";
                        echo "<tr><th>Department</th><td><span class='badge bg-info text-dark'>" . $user_data['dept'] . "</span></td></tr>";
                        echo "<tr><th>Skills</th><td>" . $user_data['skills'] . "</td></tr>";
                        echo "<tr><th>Created At</th><td>" . ($user_data['created_at'] ?? 'N/A') . "</td></tr>";
                        echo '</table>';
                    } else {
                        echo "<div class='alert alert-danger text-center'>User not found!</div>";
                    }
                } catch (PDOException $e) {
                    echo "<div class='alert alert-danger'>Database error: " . $e->getMessage() . "</div>";
                }
            } else {
                echo "<div class='alert alert-warning text-center'>No user ID provided.</div>";
            }
            ?>
        </div>
        <div class="card-footer d-flex justify-content-between">
            <a href="redirection.php" class="btn btn-secondary">Back to List</a>
            <?php if (isset($user_data)) : ?>
                <a href="edit.php?id=<?php echo $user_data['id']; ?>" class="btn btn-warning">Edit Profile</a>
            <?php endif; ?>
        </div>
    </div>
</div>

</body>
</html>
