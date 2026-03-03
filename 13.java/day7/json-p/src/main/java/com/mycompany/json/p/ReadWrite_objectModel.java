package com.mycompany.json.p;

import jakarta.json.Json;
import jakarta.json.JsonObject;
import jakarta.json.JsonReader;
import jakarta.json.JsonWriter;

import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.InputStream;
import java.io.OutputStream;
import java.nio.file.Path;
import java.nio.file.Paths;

public class ReadWrite_objectModel {

    private final String jsonFilePath;

    public ReadWrite_objectModel(String jsonFilePath) {
        this.jsonFilePath = jsonFilePath;
    }

    // Function to write a Library object to JSON
    public void writeLibrary(Library library) {
        try {
            // Compute output path in same folder as input
            Path inputPath = Paths.get(jsonFilePath);
            Path outputPath = inputPath.getParent().resolve("objectModel-" + inputPath.getFileName());

            // Build JsonObject from Library
            JsonObject jsonLibrary = Json.createObjectBuilder()
                    .add("name", library.getName())
                    .add("location", library.getLocation())
                    .add("numberOfBooks", library.getNumberOfBooks())
                    .build();

            // Write JSON to file
            try (OutputStream os = new FileOutputStream(outputPath.toString());
                 JsonWriter writer = Json.createWriter(os)) {
                writer.writeObject(jsonLibrary);
            }

            System.out.println("Library object written to: " + outputPath);

        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    // Function to read JSON and return a Library object
    public Library readLibrary() {
        Library library = null;

        try (InputStream is = new FileInputStream(jsonFilePath);
             JsonReader reader = Json.createReader(is)) {

            JsonObject jsonLibrary = reader.readObject();

            library = new Library();
            library.setName(jsonLibrary.getString("name"));
            library.setLocation(jsonLibrary.getString("location"));
            library.setNumberOfBooks(jsonLibrary.getInt("numberOfBooks"));

        } catch (Exception e) {
            e.printStackTrace();
        }

        return library;
    }

    
}
