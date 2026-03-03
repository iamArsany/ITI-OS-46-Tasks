package com.mycompany.json.p;

import jakarta.json.bind.Jsonb;
import jakarta.json.bind.JsonbBuilder;

import java.util.ArrayList;
import java.util.List;

public class JsonbMovieListExample {

    public static void main(String[] args) {
        // Step 1: Create list of movies
        List<Movie> movies = new ArrayList<>();
        movies.add(new Movie("Inception", "Christopher Nolan", 2010));
        movies.add(new Movie("The Matrix", "Wachowski Sisters", 1999));
        movies.add(new Movie("Interstellar", "Christopher Nolan", 2014));

        // Step 2: Create Jsonb and serialize list to JSON string
        Jsonb jsonb = JsonbBuilder.create();
        String jsonResult = jsonb.toJson(movies);
        System.out.println("Serialized JSON:");
        System.out.println(jsonResult);

        // Step 3: Deserialize back into a List<Movie>
        // For generic type, we use a class hint via ArrayList and cast
        List<Movie> moviesFromJson = jsonb.fromJson(jsonResult, ArrayList.class);

        // Note: moviesFromJson contains Maps if you don't provide type info
        // If you want proper Movie objects, you need JsonbConfig with type adapter or use javax.json.bind.type.Ref
        System.out.println("\nDeserialized list (raw):");
        for (Object obj : moviesFromJson) {
            System.out.println(obj);
        }
    }
}
