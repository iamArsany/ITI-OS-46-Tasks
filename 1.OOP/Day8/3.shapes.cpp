#include <iostream>

using namespace std;

class Point {
  int x, y;

public:
  Point(int x = 0, int y = 0) {
    setX(x);
    setY(y);
  }

  Point(Point &pt) {
    setX(pt.x);
    setY(pt.y);
  }

  Point(Point *pt1) { setPoint(pt1->getX(), pt1->getY()); }

  void setX(int _x) { x = _x; }
  void setY(int _y) { y = _y; }

  void setPoint(int _x, int _y) {
    setX(_x);
    setY(_y);
  }

  void SetPoint(Point &pt) {
    setX(pt.x);
    setY(pt.y);
  }

  int getX() { return x; }
  int getY() { return y; }

  void Print() { printf("\n( %d , %d )", getX(), getY()); }
};

class RectangleCompos {

  Point ul;
  Point lr;

public:
  RectangleCompos(int x1, int y1, int x2, int y2) : ul(x1, y1), lr(x2, y2) {}
  RectangleCompos(Point pt1, Point pt2) {
    ul = pt1;
    lr = pt2;
  }
  ~RectangleCompos() { cout << "RectangleCompos Destroyed!!" << endl; }
  void PrintRect() {
    cout << "UpperLeft: ";
    ul.Print();
    cout << endl;

    cout << "LowerRight: ";
    lr.Print();
    cout << endl;
  }

  // int getUl() {}
  // int getLr() {}
};

class RectangleAggreg {

  Point *ul;
  Point *lr;

public:
  RectangleAggreg(Point *pt1, Point *pt2) {
    ul = pt1;
    lr = pt2;
  }
};

class CircleCompos {
  Point pt;
  int radius;

public:
  CircleCompos(Point pt1, int _radius = 0) {
    pt.setPoint(pt1.getX(), pt1.getY());
    radius = _radius;
  }
  CircleCompos(int x1 = 0, int y1 = 0, int _radius = 0) : pt(x1, y1) {
    radius = _radius;
  }
};

class CircleAggreg {
  Point *pt;
  int radius;

public:
  CircleAggreg(Point *pt1, int _radius = 0) {
    pt = pt1;
    radius = _radius;
  }
  CircleAggreg(int x1 = 0, int y1 = 0, int _radius = 0) {
    pt = new Point(x1, y1);
    radius = _radius;
  }
};

class TrianlgeCompos {
  Point p1, p2, p3;

public:
  TrianlgeCompos(int x1, int y1, int x2, int y2, int x3, int y3)
      : p1(x1, y1), p2(x2, y2), p3(x3, y3) {}
  TrianlgeCompos(Point pt1, Point pt2, Point pt3) {
    p1 = pt1;
    p2 = pt2;
    p3 = pt3;
  }
};

class TrianlgeAggreg {
  Point *p1, *p2, *p3;

public:
  TrianlgeAggreg(Point *pt1, Point *pt2, Point *pt3) {
    p1 = pt2;
    p2 = pt2;
    p3 = pt3;
  }
};

int main() {
  cout << "\n Testing Point ";
  Point p1(1, 2), p2(3, 4), p3(&p1);
  p1.Print();
  p2.Print();
  p3.Print();

  cout << "\n Testing RectangleCompos: ";
  RectangleCompos rc1(0, 0, 5, 5);
  RectangleCompos rc2(p1, p2);

  cout << "\n Testing RectangleAggreg: ";
  RectangleAggreg ra1(&p1, &p2);

  cout << "\n Testing CircleCompos: ";
  CircleCompos cc1(p1, 10);
  CircleCompos cc2(2, 3, 7);

  cout << "\n Testing CircleAggreg: ";
  CircleAggreg ca1(&p2, 15);
  CircleAggreg ca2(4, 5, 8);

  cout << "\n Testing TrianlgeCompos: ";
  TrianlgeCompos tc1(0, 0, 3, 0, 3, 4);
  TrianlgeCompos tc2(p1, p2, p3);

  cout << "\n Testing TrianlgeAggreg: ";
  TrianlgeAggreg ta1(&p1, &p2, &p3);

  cout << "\nAll objects created successfully.\n";
  return 0;
}
