#include <bits/stdc++.h>

using namespace std;

int main() {
  string name;
  map<char, int> mapc;
  cin >> name;
  for (char ch : name) {
    mapc[ch]++;
  }

  int num = 0;
  for (pair<char, int> ch : mapc) {
    num++;
  }
  if (num % 2 == 0) {
    cout << "CHAT WITH HER!";
  } else {
    cout << "IGNORE HIM!";
  }
}
