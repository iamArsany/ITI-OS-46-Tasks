<html>
<head><title>View User Details</title></head>
<body>
    <h2>User Details</h2>

    <?php
    // 1. Check if the line index is provided in the URL
    if (isset($_GET['line'])) {
        $line_number = $_GET['line'];

        // 2. Read the file into an array
        if (file_exists("data.txt")) {
            $all_lines = file("data.txt");

            // 3. Check if that specific line exists
            if (isset($all_lines[$line_number])) {
                // 4. Get the string and split it back into an array using the comma
                $user_data = explode(",", trim($all_lines[$line_number]));

                // 5. Display the data simply
                echo "<ul>";
                echo "<li><strong>First Name:</strong> " . $user_data[0] . "</li>";
                echo "<li><strong>Last Name:</strong> " . $user_data[1] . "</li>";
                echo "<li><strong>Address:</strong> " . $user_data[2] . "</li>";
                echo "<li><strong>Gender:</strong> " . $user_data[3] . "</li>";
                echo "<li><strong>Skills:</strong> " . $user_data[4] . "</li>";
                echo "<li><strong>Department:</strong> " . $user_data[5] . "</li>";
                echo "<li><strong>Username:</strong> " . $user_data[6] . "</li>";
                echo "<li><strong>Password:</strong> " . $user_data[7] . "</li>";
                echo "</ul>";
            } else {
                echo "<p style='color:red;'>User not found!</p>";
            }
        } else {
            echo "<p style='color:red;'>Data file does not exist.</p>";
        }
    } else {
        echo "<p style='color:red;'>No user selected.</p>";
    }
    ?>

    <hr>
    <a href="redirection.php">Back to List</a>
</body>
</html>
