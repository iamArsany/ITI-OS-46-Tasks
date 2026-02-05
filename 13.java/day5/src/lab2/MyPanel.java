package lab2;

import java.awt.Color;
import java.awt.Graphics;
import javax.swing.JPanel;

public class MyPanel extends JPanel implements Runnable {
  private int x = 0;
  private int y = 100;
  private int dx = 5;

  public MyPanel() {
    setBackground(Color.CYAN);
    new Thread(this).start();
  }

  @Override
  public void paintComponent(Graphics g) {
    super.paintComponent(g);
    g.setColor(Color.BLUE);
    g.drawString("Hello", x, y);
  }

  @Override
  public void run() {
    while (true) {
      x += dx;

      if (x < 0 || x > getWidth() - 40) {
        dx *= -1;
      }
      this.repaint();

      try {
        Thread.sleep(30);
      } catch (Exception e) {
        e.printStackTrace();
      }
    }
  }
}
