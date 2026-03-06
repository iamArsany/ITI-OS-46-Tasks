<?php

namespace Classes;

use PDO;

class Database
{
    private $conn;
    private static $instance = null;

    private function __construct()
    {
        $this->conn = new PDO("mysql:host=localhost;dbname=php", "root", "1234");
        $this->conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
    }

    public static function getInstance()
    {
        if (self::$instance === null) {
            self::$instance = new self();
        }
        return self::$instance;
    }

    public function getAll(string $table, array $params = [])
    {
        $stmt = $this->conn->prepare("SELECT * FROM $table");
        $stmt->execute($params);
        return $stmt->fetchAll(PDO::FETCH_ASSOC);
    }

    public function getOne(string $table, string $column, $value)
    {
        $stmt = $this->conn->prepare("SELECT * FROM $table WHERE $column = ?");
        $stmt->execute([$value]);
        return $stmt->fetch(PDO::FETCH_ASSOC);
    }

    public function insert(string $table, array $payload)
    {
        $columns = implode(", ", array_keys($payload));
        $placeholders = implode(", ", array_fill(0, count($payload), "?"));
        $stmt = $this->conn->prepare("INSERT INTO $table ($columns) VALUES ($placeholders)");
        return $stmt->execute(array_values($payload));
    }

    public function update(string $table, array $payload, string $column, $value)
    {
        $set = implode(" = ?, ", array_keys($payload)) . " = ?";
        $stmt = $this->conn->prepare("UPDATE $table SET $set WHERE $column = ?");
        return $stmt->execute([...array_values($payload), $value]);
    }

    public function delete(string $table, string $column, $value)
    {
        $stmt = $this->conn->prepare("DELETE FROM $table WHERE $column = ?");
        return $stmt->execute([$value]);
    }
}
