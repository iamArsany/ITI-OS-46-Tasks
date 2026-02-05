#include "myStack.h"
#include <cctype>
#include <iostream>
#include <string>

using namespace std;

class StackOperations {
  string arr;

public:
  StackOperations(string input) {
    arr = input;
    DoOperation(arr);
  }
  int DoMath(myStack<int> &operands, myStack<char> &operators) {
    char op = operators.pop();
    int val2 = operands.pop();
    int val1 = operands.pop();

    switch (op) {
    case '+':
      return val1 + val2;
    case '-':
      return val1 - val2;
    case '*':
      return val1 * val2;
    case '/':
      return val1 / val2;
    default:
      return 0;
    }
  }

  int DoOperation(string str) {
    myStack<char> operators(str.size());
    myStack<int> operands(str.size());

    for (int i = 0; i < str.size(); i++) {
      if (str[i] == ' ')
        continue;

      if (isdigit(str[i])) {
        int num = 0;
        while (i < str.size() && isdigit(str[i])) {
          num = num * 10 + (str[i] - '0');
          i++;
        }
        i--;
        operands.push(num);
      } else if (str[i] == '(') {
        operators.push('(');
      } else if (str[i] == ')') {
        while (operators.peek() != '(') {
          int res = DoMath(operands, operators);
          operands.push(res);
        }
        operators.pop();
      } else if (str[i] == '+' || str[i] == '-' || str[i] == '*' ||
                 str[i] == '/') {
        while (!operators.isEmpty() &&
               HasHigherPrec(operators.peek(), str[i])) {
          int res = DoMath(operands, operators);
          operands.push(res);
        }
        operators.push(str[i]);
      }
    }

    while (!operators.isEmpty()) {
      int res = DoMath(operands, operators);
      operands.push(res);
    }
    int result = operands.pop();
    cout << "\n\nresult: " << result;
    return result;
  }

  bool HasHigherPrec(char x, char y) {
    int px = precedence(x);
    int py = precedence(y);
    return (px >= py);
  }

  int precedence(char op) {

    switch (op) {
    case '*':
    case '/':
      return 2;
    case '+':
    case '-':
      return 1;
    default:
      return 0;
    }
  }

  void print() { cout << arr; }
};

int main() {

  // myStack<int> st(10);
  // st.push(10);
  // st.push(20);
  // st.push(30);
  // myStack<int> st2(10);
  // st2 = st;
  // st2.print();
  // st2.pop();
  // st2.push(50);
  // st2.print();
  // st = st + st2;
  // cout << endl;
  // st.print();
  // st.DoOperation();

  // StackOperations expr("5+3+4*2*1*(1+3*4)");
  StackOperations exp("5+((5+3+5)*10)");
  return 0;
}
