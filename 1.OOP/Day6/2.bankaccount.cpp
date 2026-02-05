#include <cstring>
#include <iostream>

using namespace std;

class BankAccount {
  int id;
  char name[20];
  int balance = 0;

public:
  void setId(int _id) {
    if (_id > 0) {
      id = _id;
    } else {
      cout << "Invalid id" << endl;
    }
  }
  int getId() { return id; }

  void setName(char *_name) {
    if (strlen(_name) > 3) {
      strcpy(name, _name);
    } else {
      cout << "Invalid Name" << endl;
    }
  }
  char *getName() { return name; }

  int getBalance() { return balance; }

  void DepositBalance(int money) {
    if (money > 50 && money < 100000) {
      balance += money;
    } else {
      cout << "Invalid Deposit" << endl;
    }
  }

  void withdrawBalance(int money) {
    if (money <= balance) {
      balance -= money;
    } else {
      cout << "insufficient Balance" << endl;
    }
  }

  void Print() {
    cout << "id: " << id << endl;
    cout << "name: " << name << endl;
    cout << "balance: " << balance << endl;
  }
};

int main() {
  BankAccount ba;

  char name[] = "Arsany";
  ba.setId(20);
  ba.setName(name);
  ba.DepositBalance(4000);
  ba.Print();
}
