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
  Fraction(int _num = 0, int _denum = 1) {
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

  Fraction operator+(Fraction fr) {
    Fraction temp;
    int newBase = denum * fr.denum;
    int newNum = (newBase / denum * num) + (newBase / fr.denum * fr.num);
    temp.setNum(newNum);
    temp.setDenum(newBase);
    temp.simpleForm(temp.getNum(), temp.getDenum());
    return temp;
  }

  Fraction operator+(int x) {
    Fraction temp;
    temp.setNum(num + (x * denum));
    temp.setDenum(denum);
    temp.simpleForm(temp.getNum(), temp.getDenum());
    return temp;
  }

  bool operator==(Fraction fr) {
    Fraction f1 = *this;
    Fraction f2 = fr;
    f1.simpleForm(f1.getNum(), f1.getDenum());
    f2.simpleForm(f2.getNum(), f2.getDenum());
    return (f1.num == f2.num && f1.denum == f2.denum);
  }

  bool operator!=(Fraction fr) { return !(*this == fr); }

  Fraction operator++(int) {
    Fraction temp = *this;
    num = num + denum;
    simpleForm(num, denum);
    return temp;
  }

  Fraction operator++() {
    num = num + denum;
    simpleForm(num, denum);
    return *this;
  }
};

int main() {
  Fraction fr(15, 3);
  Fraction fr2(30, 3);
  fr = fr + fr2;
  fr.display();
}
