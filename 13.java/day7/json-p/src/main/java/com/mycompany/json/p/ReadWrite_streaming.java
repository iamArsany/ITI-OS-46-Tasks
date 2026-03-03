package com.mycompany.json.p;

import jakarta.json.stream.JsonParser;
import jakarta.json.stream.JsonGenerator;
import jakarta.json.Json;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.InputStream;
import java.io.OutputStream;
import java.nio.file.Paths;

public class ReadWrite_streaming {

    private final String jsonFilePath;

    public ReadWrite_streaming(String jsonFilePath) {
        this.jsonFilePath = jsonFilePath;
    }

    // Function 1: Read the JSON file and print the movie name
    public void readMovieName() {
        try (InputStream fis = new FileInputStream(jsonFilePath); JsonParser parser = Json.createParser(fis)) {

            while (parser.hasNext()) {
                JsonParser.Event event = parser.next();
                if (event == JsonParser.Event.KEY_NAME) {
                    String key = parser.getString();
                    if ("movie".equals(key)) {
                        parser.next(); // Move to VALUE_STRING
                        String movieName = parser.getString();
                        System.out.println("Movie name: " + movieName);
                        break; // Found it, stop parsing
                    }
                }
            }

        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    // Function 2: Update the movie name and write a new JSON file
    // Function 2: Update the movie name and write a new JSON file in the same folder as the input file
    public void updateMovieName(String newMovieName) {
        try {
            // Compute output path in the same directory as input JSON
            java.nio.file.Path inputPath = Paths.get(jsonFilePath);
            java.nio.file.Path outputPath = inputPath.getParent().resolve("new_output-" + inputPath.getFileName());

            try (InputStream fis = new FileInputStream(jsonFilePath); JsonParser parser = Json.createParser(fis); OutputStream fos = new FileOutputStream(outputPath.toString()); JsonGenerator generator = Json.createGenerator(fos)) {

                generator.writeStartObject(); // Start writing root object

                while (parser.hasNext()) {
                    JsonParser.Event event = parser.next();

                    if (event == JsonParser.Event.KEY_NAME) {
                        String key = parser.getString();
                        JsonParser.Event valueEvent = parser.next(); // get value event

                        if ("movie".equals(key)) {
                            generator.write(key, newMovieName); // Replace movie name
                        } else {
                            switch (valueEvent) {
                                case VALUE_STRING:
                                    generator.write(key, parser.getString());
                                    break;
                                case VALUE_NUMBER:
                                    generator.write(key, parser.getInt());
                                    break;
                                case VALUE_TRUE:
                                    generator.write(key, true);
                                    break;
                                case VALUE_FALSE:
                                    generator.write(key, false);
                                    break;
                                case VALUE_NULL:
                                    generator.writeNull(key);
                                    break;
                                default:
                                // Other events ignored for simplicity
                            }
                        }
                    }
                }

                generator.writeEnd(); // End root object
                System.out.println("Updated JSON written to: " + outputPath);

            }

        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    // Example main method to test
}
