package lab3;

import javax.swing.JFrame;

/**
 * BouncyBall
 */
public class BouncyBall extends JFrame {

  public static void main(String[] args) {
    JFrame frame = new JFrame("BouncyBall");
    MyPanel mp = new MyPanel();
    frame.setContentPane(mp);
    frame.setSize(500, 300);
    frame.setLocationRelativeTo(null);
    frame.setVisible(true);
    System.out.println(frame.getWidth());
    System.out.println(frame.getHeight());
  }

}
