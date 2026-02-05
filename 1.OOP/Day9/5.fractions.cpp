#include <iostream>

using namespace std;

int gcd(int a, int b) {
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

class Fraction {
  int num, denum;

public:
  Fraction(int _num, int _denum) {
    setNum(_num);
    setDenum(_denum);
  }
  void setNum(int _num) { num = _num; }

  void setDenum(int _denum) {
    if (_denum == 0) {
      cout << "denom cannot be zero" << endl;
      return;
    } else {
      denum = _denum;
    }
  }
  int getNum() { return num; }
  int getDenum() { return denum; }

  void display() {
    simpleForm(getNum(), getDenum());
    cout << num << "/" << denum << endl;
  }

  void simpleForm(int a, int b) {
    int g = gcd(a, b);
    a /= g;
    b /= g;
    setNum(a);
    setDenum(b);
    printf("\na: %i ,b: %i\n", a, b);
  }

  void sum(Fraction fr) {
    // 5/3  + 2/4 =   20+6/12
    int newBase = getDenum() * fr.getDenum();
    int newEnum1 = newBase / this->getDenum() * this->getNum();
    int newEnum2 = newBase / fr.getDenum() * fr.getNum();

    this->setNum(newEnum1 + newEnum2);
    this->setDenum(newBase);
  }
};

int main() {
  Fraction fr(15, 3);
  Fraction fr2(30, 3);
  fr.sum(fr2);
  fr.display();
}
