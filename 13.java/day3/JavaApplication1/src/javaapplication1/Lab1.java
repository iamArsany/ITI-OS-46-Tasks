package javaapplication1;

public class Lab1{

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
      System.out.println("lab1 project");
      TemperatureConversion temp=new TemperatureConversion();
      float result=temp.apply(1F);
      System.out.println("result: "+result);
    }

}
