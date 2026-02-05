package lab3;

import java.util.ArrayList;

/**
 * Test
 */
public class Test {

  public static void main(String[] args) {
    System.out.println("Testing the main");
    ArrayList<Rectangle> rectList = new ArrayList<Rectangle>();
    ArrayList<Circle> circList = new ArrayList<Circle>();
    rectList.add(new Rectangle());
    rectList.add(new Rectangle());
    circList.add(new Circle());
    circList.add(new Circle());

    Test testClass = new Test();

    try {
      testClass.allowShapeInheritedObjects(rectList);
      testClass.allowShapeInheritedObjects(circList);
    } catch (Exception e) {
      e.printStackTrace();
    }

  }

  public void allowShapeInheritedObjects(ArrayList<? extends Shape> sh) {

  }
}
