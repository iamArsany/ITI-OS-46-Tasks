#include <iostream>

using namespace std;

class Complex {

  int real;
  int img;

public:
  Complex(int real = 0, int img = 0) {
    setReal(real);
    setImg(img);
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
};

Complex subtract(Complex c1, Complex c2) {
  Complex res;
  res.setReal(c1.getReal() - c2.getReal());
  res.setImg(c1.getImg() - c2.getImg());
  return res;
}

void print(Complex c) {
  if (c.getImg() > 0) {
    cout << c.getReal() << " + " << c.getImg() << "i" << endl;
  } else if (c.getImg() == 0) {
    cout << c.getReal() << endl;
  } else {
    cout << c.getReal() << c.getImg() << "i" << endl;
  }
}

int main() {
  Complex c1, c2, sum, diff;

  // c1.setReal(3);
  // c1.setImg(2);

  // c2.setReal(1);
  // c2.setImg(7);

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
  return 0;
}
