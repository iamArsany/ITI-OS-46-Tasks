#include <cstring>
#include <iostream>
#include <ncurses.h>
using namespace std;

struct Employee {
  int id;
  char name[20];
  int age;
};

Employee employees[10];
bool employeesExist[10] = {false};

void clearScreen() {
  clear();
  refresh();
}

void initNcurses() {
  initscr();
  cbreak();
  noecho();
  keypad(stdscr, TRUE);
  curs_set(0);
  start_color();

  init_pair(1, COLOR_RED, COLOR_BLACK);
  init_pair(2, COLOR_WHITE, COLOR_BLACK);
}

void textattr(int i) { attron(COLOR_PAIR(i)); }

void gotoxy(int x, int y) {
  move(x, y);
  refresh();
}

void displayMenu(int hIndex) {
  clearScreen();

  if (hIndex == 0)
    textattr(1);
  else
    textattr(2);
  gotoxy(6, 10);
  printw("New");

  if (hIndex == 1)
    textattr(1);
  else
    textattr(2);
  gotoxy(7, 10);
  printw("Display");

  if (hIndex == 2)
    textattr(1);
  else
    textattr(2);
  gotoxy(8, 10);
  printw("Exit");

  refresh();
}

void AddEmployee() {
  clearScreen();

  echo();
  curs_set(1);

  int index, id, age;
  char name[20];

  gotoxy(5, 5);
  printw("Enter Index from 1 to 10: ");
  scanw("%d", &index);

  if (index < 1 || index > 10) {
    gotoxy(7, 5);
    printw("Invalid index. Press any key...");
    getch();
    noecho();
    curs_set(0);
    return;
  }

  int i = index - 1;

  if (employeesExist[i]) {
    gotoxy(7, 5);
    printw("Employee Exists. Press any key...");
    getch();
  } else {
    gotoxy(7, 5);
    printw("Enter Id , Name ,Age: ");
    scanw("%d %19s", &id, name, &age);

    employees[i].id = id;
    strcpy(employees[i].name, name);
    employeesExist[i] = true;

    gotoxy(9, 5);
    printw("Employee added successfully! ");
    getch();
  }

  noecho();
  curs_set(0);
}

void DisplayEmployees() {
  clearScreen();
  gotoxy(3, 5);
  printw("Employees List: ");

  int y = 5;
  bool found = false;
  for (int i = 0; i < 10; i++) {
    if (employeesExist[i]) {
      gotoxy(y++, 5);
      printw("Index %d => ID: %d , Name: %s , Age: %d", i + 1, employees[i].id,
             employees[i].name, employees[i].age);
      found = true;
    }
  }

  if (!found) {
    gotoxy(y, 5);
    printw("No employees found.");
  }

  gotoxy(y + 2, 5);
  printw("Press any key to return...");
  getch();
}

int main() {
  initNcurses();

  int hIndex = 0;
  displayMenu(hIndex);

  while (true) {
    int input = getch();

    switch (input) {
    case 27: // ESC
      endwin();
      return 0;

    case KEY_UP:
      hIndex--;
      if (hIndex < 0)
        hIndex = 2;
      break;

    case KEY_DOWN:
      hIndex++;
      if (hIndex > 2)
        hIndex = 0;
      break;

    case '\n':
      if (hIndex == 0) {
        AddEmployee();
      } else if (hIndex == 1) {
        DisplayEmployees();
      } else if (hIndex == 2) {
        endwin();
        return 0;
      }
      break;
    }

    displayMenu(hIndex);
  }

  endwin();
  return 0;
}
