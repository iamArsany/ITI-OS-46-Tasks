#include <iostream>

using namespace std;

class Complex {

  int real;
  int img;
  static int counter;

public:
  Complex(int real = 0, int img = 0) {
    setReal(real);
    setImg(img);
    Complex::counter++;
  }
  Complex(Complex &c) {
    setReal(c.real);
    setImg(c.img);
    Complex::counter++;
  }
  ~Complex() { Complex::counter--; }
  friend void print(Complex c);
  static void getCounter() {
    cout << "\n Counter: " << Complex::counter << endl;
  }
  void setReal(int _real) {
    if (typeid(_real) == typeid(int)) // ❌ always true
      real = _real;
    else
      cout << "Not an int" << endl;
  }
  void setImg(int _img) {
    if (typeid(_img) == typeid(int)) // ❌ always true
      img = _img;
    else
      cout << "Not an int" << endl;
  }

  int getReal() { return real; }
  int getImg() { return img; }

  Complex add(Complex c1) {
    Complex res;
    res.setReal(real + c1.real);
    res.setImg(img + c1.img);
    return res;
  }

  void print(Complex c) {
    if (c.img > 0) {
      cout << c.real << " + " << c.img << "i" << endl;
    } else if (c.img == 0) {
      cout << c.real << endl;
    } else {
      cout << c.real << c.img << "i" << endl;
    }
  }

  Complex operator+(Complex c) {
    setReal(real + c.real);
    setImg(img + c.img);
    return *this;
  }

  bool operator==(Complex c) { return (real == c.real) && (img == c.img); }
  bool operator!=(Complex c) { return !this->operator==(c); }

  Complex operator++() {
    ++img;
    ++real;
    return *this;
  }

  Complex operator++(int) {
    Complex temp = *this;
    ++real;
    ++img;
    return temp;
  }

  Complex operator+(int x) {
    this->setReal(this->real + x);
    return *this;
  }

  Complex operator=(Complex c) {
    setReal(c.real);
    setImg(c.img);
    return *this;
  }

  operator int() {
    int x = this->real;
    return x;
  }
};

int Complex::counter = 0;
Complex subtract(Complex c1, Complex c2) {
  Complex res;
  res.setReal(c1.getReal() - c2.getReal());
  res.setImg(c1.getImg() - c2.getImg());
  return res;
}

Complex operator+(int x, Complex c) {
  c.setReal(x + c.getReal());
  return c;
}

void print(Complex c) {
  if (c.img > 0) {
    cout << c.real << " + " << c.img << "i" << endl;
  } else if (c.img == 0) {
    cout << c.real << endl;
  } else {
    cout << c.real << c.img << "i" << endl;
  }
}

int main() {
  Complex c1, c2, sum, diff;

  // c1.setReal(3);
  // c1.setImg(2);

  // c2.setReal(1);
  // c2.setImg(7);
  Complex::getCounter();
  cout << "C1 = ";
  print(c1);
  cout << "C2 = ";
  print(c2);

  sum = c1.add(c2);
  cout << "Sum = ";
  print(sum);

  diff = subtract(c1, c2);
  cout << "Difference = ";
  print(diff);
  Complex::getCounter();

  Complex arsany = c1.add(c2);

  return 0;
}
