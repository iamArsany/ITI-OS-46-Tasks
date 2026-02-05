package lab3;

import java.awt.Color;
import java.awt.Graphics;
import javax.swing.JPanel;

public class MyPanel extends JPanel implements Runnable {
  private int x = 0;
  private int y = 0;
  private int dx = 5;
  private int dy = 5;
  private final int BALL_SIZE = 50;

  public MyPanel() {
    setBackground(Color.CYAN);
    new Thread(this).start();
  }

  @Override
  protected void paintComponent(Graphics g) {
    super.paintComponent(g);
    g.setColor(Color.RED);
    g.fillOval(x, y, BALL_SIZE, BALL_SIZE);
  }

  @Override
  public void run() {
    while (true) {
      x += dx;
      y += dy;

      if (x < 0 || x > getWidth() - BALL_SIZE) {
        dx *= -1;
      }

      if (y < 0 || y > getHeight() - BALL_SIZE) {
        dy *= -1;
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
