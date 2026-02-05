package game;

import javax.swing.JFrame;

public class Game extends JFrame implements Runnable {

  private Thread gameThread;
  private GamePanel panel;

  public Game() {
    setTitle("My 2D Java Game");
    setSize(800, 1000);
    setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    setResizable(false);
    setLocationRelativeTo(null);

    panel = new GamePanel();
    add(panel);

    setVisible(true);
  }

  public void start() {
    gameThread = new Thread(this);
    gameThread.start();
  }

  @Override
  public void run() {
    while (true) {
      update();
      render();

      try {
        Thread.sleep(16);
      } catch (InterruptedException e) {
        e.printStackTrace();
      }
    }
  }

  private void update() {
    // game logic later
  }

  private void render() {
    panel.repaint();
  }
}
