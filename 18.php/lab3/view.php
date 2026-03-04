<html>
<head><title>View User Details</title></head>
<body>
    <h2>User Details</h2>

    <?php
    if (isset($_GET['id'])) {
        $user_id = $_GET['id'];

        $host = "localhost";
        $user = "root";
        $pass = "1234";
        $db   = "php";

        try {
            $conn = new PDO("mysql:host=$host;dbname=$db", $user, $pass);

            $stmt = $conn->prepare("SELECT * FROM users WHERE id = ?");
            $stmt->execute([$user_id]);
            $user_data = $stmt->fetch(PDO::FETCH_ASSOC);

            if ($user_data) {
                echo "<ul>";
                echo "<li><strong>ID:</strong> " . $user_data['id'] . "</li>";
                echo "<li><strong>First Name:</strong> " . $user_data['fname'] . "</li>";
                echo "<li><strong>Last Name:</strong> " . $user_data['lname'] . "</li>";
                echo "<li><strong>Address:</strong> " . $user_data['address'] . "</li>";
                echo "<li><strong>Country:</strong> " . $user_data['country'] . "</li>";
                echo "<li><strong>Gender:</strong> " . $user_data['gender'] . "</li>";
                echo "<li><strong>Department:</strong> " . $user_data['dept'] . "</li>";
                echo "<li><strong>Skills:</strong> " . $user_data['skills'] . "</li>";
                echo "<li><strong>Username:</strong> " . $user_data['username'] . "</li>";
                echo "<li><strong>Password:</strong> " . $user_data['password'] . "</li>";
                echo "<li><strong>Created At:</strong> " . $user_data['created_at'] . "</li>";
                echo "</ul>";
            } else {
                echo "<p style='color:red;'>User not found in the database!</p>";
            }
        } catch (PDOException $e) {
            echo "Database error: " . $e->getMessage();
        }
    } else {
        echo "<p style='color:red;'>No ID provided in the URL.</p>";
    }
    ?>

    <hr>
    <a href="redirection.php">Back to List</a>
</body>
</html>
