package lab1;

import javax.swing.JFrame;

public class DateTimeUpdate {
  public static void main(String[] args) {
    JFrame frame = new JFrame("Time Updated");
    MyPanel mp = new MyPanel();
    frame.setContentPane(mp);
    frame.setSize(500, 300);
    frame.setVisible(true);
    System.out.println(frame.getWidth());
    System.out.println(frame.getHeight());
  }

}
