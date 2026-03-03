/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 */

package com.mycompany.json.p;

/**
 *
 * @author miles
 */
public class JsonP {

    public static void main(String[] args) {
        
        //first task
        String path = "src/main/java/com/mycompany/json/p/json-schema.json";
        ReadWrite_streaming rw = new ReadWrite_streaming(path);

        rw.readMovieName();
        rw.updateMovieName("New Movie Title");
        
        
        
        //second task
        String libPath = "src/main/java/com/mycompany/json/p/library.json"; // adjust to your JSON file
        ReadWrite_objectModel rw_2 = new ReadWrite_objectModel(libPath);

        
        Library lib = new Library("Downtown Library", "City Center", 8500);
        rw_2.writeLibrary(lib);

        // read it back
        Library readLib = rw_2.readLibrary();
        System.out.println("Library read from JSON: " + readLib);
    }
    

    
}
