package com.iti;

public class Main {
    public static void main(String[] args) {
        DatabaseConnector db=DatabaseConnector.getInstance("sql","connectionstringTest");
        DatabaseConnector db1=DatabaseConnector.getInstance("sql","connectionstringTest");
        DatabaseConnector db2=DatabaseConnector.getInstance("sql","connectionstringTest");
        DatabaseConnector db3=DatabaseConnector.getInstance("sql","connectionstringTest");




    }
}

