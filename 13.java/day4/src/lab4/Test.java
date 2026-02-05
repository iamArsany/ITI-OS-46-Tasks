package lab4;

public class Test {
  public static void main(String[] args) {
    Complex<Double> z1 = new DoubleComplex(3.0, 4.0);
    Complex<Double> z2 = new DoubleComplex(1.0, 2.0);

    Complex<Double> sum = z1.add(z2);
    System.out.println(sum.getReal());
    System.out.println(sum.getImaginary());

    Complex<Double> diff = z1.subtract(z2);
    System.out.println(diff.getReal());
    System.out.println(diff.getImaginary());

    Complex<Double> prod = z1.product(z2);
    System.out.println(prod.getReal());
    System.out.println(prod.getImaginary());

    try {
      Complex<Double> div = z1.div(z2);
      System.out.println(div.getReal());
      System.out.println(div.getImaginary());

    } catch (Exception e) {
      System.out.println("error inside the Exception division");
    }
  }
}
