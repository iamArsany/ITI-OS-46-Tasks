#include <iostream>

using namespace std;

void gotoxy(int x, int y, int xSpacing = 4, int ySpacing = 2) {
  int scaledX = x * xSpacing + 30;
  int scaledY = y * ySpacing + 4;
  cout << "\033[" << scaledY << ";" << scaledX << "H";
}

void clearScreen() { cout << "\033[2J\033[1;1H"; }

int main() {
  int size;
start_program:

  cout << "Enter your Magic Box Size: ";
  cin >> size;
  if (size % 2 == 0) {
    cout << "Only Odd numbers!";
    goto start_program;
  } else if (size < 3) {
    cout << "Magic box size must be >= 3";
    goto start_program;
  } else {
    // clearScreen();
  }

  // 1.first rule
  int x = ((size - 1) / 2) + 1;
  int y = 1;
  gotoxy(x, y);
  cout << 1;

  int max = size * size;
  for (int i = 2; i <= max; i++) {
    int res = (i - 1) % size;
    if (res != 0) {
      if (x - 1 != 0) {
        x -= 1;
      } else {
        x = size;
      }

      if (y - 1 != 0) {
        y -= 1;
      } else {
        y = size;
      }
    } else {
      if (y + 1 > size) {
        y = 1;
      } else {
        y += 1;
      }
    }
    gotoxy(x, y);
    cout << i;
  }
}
