package game;

import javax.swing.JPanel;
import java.awt.Color;
import java.awt.Graphics;

public class GamePanel extends JPanel {

  public GamePanel() {
    setBackground(Color.BLACK);
  }

  @Override
  protected void paintComponent(Graphics g) {
    super.paintComponent(g); // clears the screen

    // Draw a triangle in the middle
    g.setColor(Color.WHITE);

    int width = getWidth();
    int height = getHeight();

    int[] xPoints = {
        width / 2,
        width / 2 - 50,
        width / 2 + 50
    };

    int[] yPoints = {
        height / 2 - 50,
        height / 2 + 50,
        height / 2 + 50
    };

    g.drawString("Hello first game", 10, 10);
    g.fillPolygon(xPoints, yPoints, 3);
  }
}
