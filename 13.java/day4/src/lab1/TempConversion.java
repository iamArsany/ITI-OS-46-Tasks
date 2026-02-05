package lab1;

import java.util.function.Function;

public class TempConversion {
  public static void main(String[] args) {

    TempConversion outer = new TempConversion();
    InnerConversion output = outer.new InnerConversion();
    System.out.println(output.apply(10f));
  }

  public class InnerConversion implements Function<Float, Float> {
    public Float apply(Float x) {
      return (x * 1.82F) + 32;
    }
  }
}
