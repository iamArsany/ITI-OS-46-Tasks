package com.iti;

public class DatabaseConnector {
    private static DatabaseConnector instance;

    private DatabaseConnector(String connectionType, String connectionString) {
        System.out.println("creating Object: " + 1 + 2 + connectionString + " : " + connectionType);
    }

    public static DatabaseConnector getInstance(String connectionType, String connectionString) {
        try {
            if (DatabaseConnector.instance instanceof DatabaseConnector) {
                System.out.println("Already created!");
                return DatabaseConnector.instance;
            } else {
                DatabaseConnector db = new DatabaseConnector(connectionType, connectionString);
                DatabaseConnector.instance = db;
                return db;
            }

        } catch (Exception e) {
            return null;
        }

    }
}
