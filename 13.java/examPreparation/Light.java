import java.io.IOException;

public class Light {

  public static void main(String[] v) throws Exception {
    try {
      new Light().turnOn();
    } catch (RuntimeException v) { // renamed to avoid confusion
      System.out.println(v);
      throw new IOException();
    } finally {
      System.out.println("complete");
    }
  }

  public void turnOn() throws IOException {
    new IOException("Not ready"); // created but NOT thrown
  }
}
