<?php
if (isset($_GET['line'])) {
    $line_index = $_GET['line'];

    if (file_exists("data.txt")) {
        $all_lines = file("data.txt");

        if (isset($all_lines[$line_index])) {
            unset($all_lines[$line_index]);

            file_put_contents("data.txt", implode("", $all_lines));
        }
    }
}

header("Location: redirection.php");
exit();
?>
