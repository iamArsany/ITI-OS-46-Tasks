package lab4;

/**
 * DoubleComplex
 */
public class DoubleComplex implements Complex<Double> {
  private Double real;
  private Double imaginary;

  public DoubleComplex(Double r, Double i) {
    this.real = r;
    this.imaginary = i;
  }

  public Double getReal() {
    return this.real;
  }

  public Double getImaginary() {
    return this.imaginary;
  }

  public DoubleComplex add(Complex<Double> z) {
    return new DoubleComplex(
        this.getReal() + z.getReal(),
        this.getImaginary() + z.getImaginary());
  }

  public DoubleComplex subtract(Complex<Double> z) {
    return new DoubleComplex(
        this.getReal() - z.getReal(),
        this.getImaginary() - z.getImaginary());
  }

  public DoubleComplex product(Complex<Double> z) {
    double a = this.getReal();
    double b = this.getImaginary();
    double c = z.getReal();
    double d = z.getImaginary();

    // Formula: (ac - bd) + (ad + bc)i
    return new DoubleComplex(
        (a * c) - (b * d),
        (a * d) + (b * c));
  }

  public DoubleComplex div(Complex<Double> z) throws Exception {
    double a = this.getReal();
    double b = this.getImaginary();
    double c = z.getReal();
    double d = z.getImaginary();

    double denominator = (c * c) + (d * d);

    if (denominator == 0) {
      throw new Exception("Division by zero");
    }

    // Formula: ((ac + bd) / denominator) + ((bc - ad) / denominator)i
    double resReal = (a * c + b * d) / denominator;
    double resImaginary = (b * c - a * d) / denominator;

    return new DoubleComplex(resReal, resImaginary);
  }
}
