package com.mycompany.json.p;

public class Library {

    private String name;
    private String location;
    private int numberOfBooks;

    public Library() {
    }

    public Library(String name, String location, int numberOfBooks) {
        this.name = name;
        this.location = location;
        this.numberOfBooks = numberOfBooks;
    }

   
    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getLocation() {
        return location;
    }

    public void setLocation(String location) {
        this.location = location;
    }

    public int getNumberOfBooks() {
        return numberOfBooks;
    }

    public void setNumberOfBooks(int numberOfBooks) {
        this.numberOfBooks = numberOfBooks;
    }

    @Override
    public String toString() {
        return "Library{" +
                "name='" + name + '\'' +
                ", location='" + location + '\'' +
                ", numberOfBooks=" + numberOfBooks +
                '}';
    }
}
