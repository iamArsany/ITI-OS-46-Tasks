package QuadraticEquationSolver;

import java.util.function.Function;

public class QuadraticSolverClass implements Function<double[], String> {

    private double a;
    private double b;
    private double c;

    @Override
    public String apply(double[] v) {
      this.a=v[0];
      this.b=v[1];
      this.c=v[2];

        double d = (b * b) - (4 * a * c);
        double r = -b / (2 * a);

        if (d > 0) {
            double res1 = r + (Math.sqrt(d) / (2 * a));
            double res2 = r - (Math.sqrt(d) / (2 * a));
            return ("Roots are real: \nFirst root: " + res1 + "\nSecond root: " + res2);
        } else if (d == 0) {
            return "Roots are equal \nRoot: " + r;
        } else {
            d = -d;
            double im = Math.sqrt(d) / (2 * a);
            return "Roots are imaginary \nFirst root: " + r + " + i" + im + "\nSecond root: " + r + " - i" + im;
        }
    }
}

