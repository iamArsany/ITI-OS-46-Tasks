package lab2;

/**
 * SecondClass
 */
public class SecondClass {

  public static void main(String[] args) {
    FirstClass callErrorMethod = new FirstClass();
    // M1 call
    try {
      callErrorMethod.m1();
    } catch (Exception e) {
      System.out.println("M1 error stackTrace");
      e.printStackTrace();
    }

    // M2 call
    try {
      callErrorMethod.m2();
    } catch (Exception e) {
      System.out.println("M2 error stackTrace");
      e.printStackTrace();
    }

    // M3 Call
    try {
      callErrorMethod.m3();
    } catch (Exception e) {
      System.out.println("M3 error stackTrace");
      e.printStackTrace();
    }

  }
}
