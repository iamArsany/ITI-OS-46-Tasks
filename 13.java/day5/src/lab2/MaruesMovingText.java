package lab2;

import javax.swing.JFrame;

/**
 * MaruesMovingText
 */
public class MaruesMovingText extends JFrame {

  public static void main(String[] args) {
    JFrame frame = new JFrame("Moving Text Updated");
    MyPanel mp = new MyPanel();
    frame.setContentPane(mp);
    frame.setSize(500, 300);
    frame.setVisible(true);
    System.out.println(frame.getWidth());
    System.out.println(frame.getHeight());
  }
}
