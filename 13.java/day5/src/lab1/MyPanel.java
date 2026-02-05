package lab1;

import java.awt.Color;
import java.awt.Graphics;
import java.sql.Date;

import javax.swing.JPanel;

public class MyPanel extends JPanel implements Runnable {
  public MyPanel() {
    setBackground(Color.CYAN);
    new Thread(this).start();
  }

  @Override
  public void paintComponent(Graphics g) {
    super.paintComponent(g);
    String date = new java.util.Date().toString();
    g.drawString(date, 30, 30);
    g.setColor(Color.BLUE);
  }

  @Override
  public void run() {
    while (true) {
      try {
        this.repaint();
        Thread.sleep(1000);
      } catch (Exception e) {
        e.printStackTrace();
      }

    }
  }
}
