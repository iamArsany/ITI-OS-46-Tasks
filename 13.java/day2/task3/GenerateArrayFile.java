import java.io.FileWriter;
import java.io.IOException;
import java.util.Random;

public class GenerateArrayFile {

    public static void main(String[] args) {
        int size = 1000;
        int[] arr = new int[size];
        Random random = new Random();

        for (int i = 0; i < size; i++) {
            arr[i] = random.nextInt(10000); 
        }
        try (FileWriter writer = new FileWriter("array.txt")) {
            writer.write("int[] arr = {\n");
            for (int i = 0; i < size; i++) {
                writer.write(arr[i] + (i < size - 1 ? ", " : ""));
                if ((i + 1) % 20 == 0) {
                    writer.write("\n");
                }
            }
            writer.write("\n};");
            System.out.println("array.txt created successfully!");
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}

