<?php

$Array_t = array("asdf" => "test3","asdff" => "test2","asdfff" => "test","asdffff" => "test","asdfffs" => "test1");

$i = 0;
echo Count($Array_t) . "<br>";
$Array_t . "<br>";

foreach ($Array_t as $val) {
    echo "{$val} {$i} <br>";
    $i++;
}
