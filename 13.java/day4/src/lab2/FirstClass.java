package lab2;

/**
 * FirstClass
 */
public class FirstClass {

  public void m1() throws ExceptionInstance {
    System.out.println("M1 in FirstClass");
    throw new ExceptionInstance();
  }

  public void m2() throws ExceptionInstance {
    System.out.println("M2 in FirstClass");
    throw new ExceptionInstance();
  }

  public void m3() throws ExceptionInstance {
    System.out.println("M3 in FirstClass");
    throw new ExceptionInstance();
  }
}
