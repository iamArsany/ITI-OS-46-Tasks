<html>

<link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.8/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-sRIl4kxILFvY47J16cr9ZwB07vP4J8+LH7qKQnuqkuIAvNWLzeN8tE5YBujZqJLB" crossorigin="anonymous">

<head><title>All Users</title></head>
<body>
    <h2>User Data List</h2>
    <table border="1" cellpadding="10" class="table">
    <tr>
        <th>Line #</th>
        <th>First Name</th>
        <th>Last Name</th>
        <th>Address</th>
        <th>Country</th> <th>Gender</th>
        <th>Skills</th>
        <th>Department</th>
        <th>Username</th>
        <th>Password</th>
        <th>Actions</th>
    </tr>
    <?php
    if (file_exists("data.txt")) {
        $all_lines = file("data.txt");

        foreach ($all_lines as $index => $line) {
            $row = explode(",", trim($line));
            if (count($row) < 2) continue;

            echo "<tr>";
          echo "<td>" . ($index + 1) . "</td>";

        foreach ($row as $data) {
           echo "<td>" . $data . "</td>";
           }

    echo "<td>
            <a href='view.php?line=" . $index . "'>View</a> | 
            <a href='delete.php?line=" . $index . "'>Delete</a>
          </td>";
    echo "</tr>";
        }
    }
    ?>
  </table>
    <br>
    <a href="registration.php">Add New User</a>
</body>
</html>
