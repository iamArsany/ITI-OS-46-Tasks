package com.mycompany.xml.test2;

import java.util.List;


public class Library {

    private String location;
    private String description;
    private String librarian;
    private List<Book> books;

    public Library() {}

    public String getLocation() { return location; }
    public void setLocation(String location) { this.location = location; }

    public String getDescription() { return description; }
    public void setDescription(String description) { this.description = description; }

    public String getLibrarian() { return librarian; }
    public void setLibrarian(String librarian) { this.librarian = librarian; }

    public List<Book> getBooks() { return books; }
    public void setBooks(List<Book> books) { this.books = books; }
}
