#include <iostream>
#include <ncurses.h>
#include <string>

using namespace std;

/* ================= LINKED LIST (UNCHANGED LOGIC) ================= */

struct Employee {
  int id;
  string name;
  int age;

  Employee(int _id, string _name, int _age) {
    id = _id;
    name = _name;
    age = _age;
  }
};

struct Node {
  Employee *emp;
  Node *prev;
  Node *next;
};

class LinkedList {
private:
  Node *head;
  Node *tail;
  int counter = 0;

  Node *searchById(int _id) {
    if (head == NULL)
      return NULL;
    Node *tmp = head;
    while (tmp) {
      if (tmp->emp->id == _id)
        return tmp;
      tmp = tmp->next;
    }
    return NULL;
  }

public:
  LinkedList() {
    head = NULL;
    tail = NULL;
  }

  void append(int id, string name, int age) {
    Employee *employee = new Employee(id, name, age);
    Node *tmp = new Node();
    tmp->emp = employee;
    tmp->next = NULL;

    if (head == NULL) {
      head = tail = tmp;
      tmp->prev = NULL;
      return;
    }

    tail->next = tmp;
    tmp->prev = tail;
    tail = tmp;
  }

  void displayAll() {
    Node *tmp = head;
    int row = 3;

    if (!tmp) {
      printw("No employees to display!");
      return;
    }

    printw("ID\tName\tAge\n");
    printw("---------------------\n");

    while (tmp) {
      printw("%d\t%s\t%d\n", tmp->emp->id, tmp->emp->name.c_str(),
             tmp->emp->age);
      tmp = tmp->next;
    }
  }

  Employee *search(int _id) {
    Node *tmp = searchById(_id);
    if (tmp)
      return tmp->emp;
    return nullptr;
  }

  int count() {
    counter = 0;
    Node *tmp = head;
    while (tmp) {
      counter++;
      tmp = tmp->next;
    }
    return counter;
  }

  bool deleteById(int _id) {
    Node *tmp = searchById(_id);
    if (tmp == NULL) {
      return false;
    }

    // If it's the head
    if (tmp == this->head) {

      if (this->head == this->tail) {
        deleteAll();
        return true;
      }

      // If there are multiple nodes
      Node *node = this->head;
      this->head = this->head->next;
      this->head->prev = NULL;

      delete node->emp;
      delete node;
      return true;
    }

    // If it's the tail
    if (tmp == this->tail) {
      Node *node = this->tail;
      this->tail = this->tail->prev;
      this->tail->next = NULL;

      delete node->emp;
      delete node;
      return true;
    }

    // If it's a middle node
    tmp->prev->next = tmp->next;
    tmp->next->prev = tmp->prev;

    delete tmp->emp;
    delete tmp;
    return true;
  }

  void deleteAll() {
    Node *tmp = head;
    while (tmp) {
      Node *current = tmp;
      tmp = tmp->next;
      delete current->emp;
      delete current;
    }
    head = tail = NULL;
  }
};

/* ================= NCURSES MENU ================= */

LinkedList ll;

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

void gotoxy(int x, int y) { move(x, y); }

void displayMenu(int hIndex) {
  clearScreen();

  const char *menu[] = {"Append", "Search",     "Display", "Count",
                        "Delete", "Delete All", "Exit"};

  for (int i = 0; i < 7; i++) {
    textattr(hIndex == i ? 1 : 2);
    gotoxy(5 + i, 10);
    printw(menu[i]);
  }
  refresh();
}

/* ================= MENU ACTIONS ================= */

void menuAppend() {
  echo();
  curs_set(1);
  clearScreen();

  int id, age;
  char name[50];

  printw("Enter ID: ");
  scanw("%d", &id);

  printw("Enter Name: ");
  scanw("%s", name);

  printw("Enter Age: ");
  scanw("%d", &age);

  ll.append(id, name, age);

  noecho();
  curs_set(0);
}

void menuSearch() {
  echo();
  curs_set(1);
  clearScreen();

  int id;
  printw("Enter ID to search: ");
  scanw("%d", &id);

  Employee *emp = ll.search(id);
  clearScreen();

  if (emp) {
    printw("FOUND\nID: %d\nName: %s\nAge: %d", emp->id, emp->name.c_str(),
           emp->age);
  } else {
    printw("Employee not found!");
  }

  noecho();
  curs_set(0);
  getch();
}

void menuCount() {
  clearScreen();
  printw("Total Employees: %d", ll.count());
  getch();
}

void menuDeleteAll() {
  clearScreen();
  ll.deleteAll();
  printw("All employees deleted!");
  getch();
}

void menuDeleteById() {
  clearScreen();

  int id;
  printw("Enter Employee ID to delete: ");
  scanw("%d", &id);

  if (ll.deleteById(id)) {
    printw("\nEmployee deleted successfully!");
  } else {
    printw("\nEmployee with ID %d not found!", id);
  }

  getch();
}

void menuDisplayAll() {
  clearScreen();
  ll.displayAll();
  getch();
}

/* ================= MAIN ================= */

int main() {
  initNcurses();

  int hIndex = 0;
  const int maxIdx = 6;

  displayMenu(hIndex);

  while (true) {
    int input = getch();

    switch (input) {
    case 27: // ESC
      endwin();
      return 0;

    case KEY_UP:
      hIndex = (hIndex == 0) ? maxIdx : hIndex - 1;
      break;

    case KEY_DOWN:
      hIndex = (hIndex == maxIdx) ? 0 : hIndex + 1;
      break;

    case '\n':
      if (hIndex == 0)
        menuAppend();
      else if (hIndex == 1)
        menuSearch();
      else if (hIndex == 2)
        menuDisplayAll();
      else if (hIndex == 3)
        menuCount();
      else if (hIndex == 4)
        menuDeleteById();
      else if (hIndex == 5)
        menuDeleteAll();
      else {
        endwin();
        return 0;
      }
      break;
    }

    displayMenu(hIndex);
  }
}
