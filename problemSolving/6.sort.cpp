#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  int arr[3], sorted[3], x;

  for (int i = 0; i < 3; i++) {
    cin >> x;
    arr[i] = sorted[i] = x;
  }
  sort(sorted, sorted + 3);
  for (int i = 0; i < 3; i++) {
    cout << sorted[i] << endl;
  }
  cout << endl;
  for (int i = 0; i < 3; i++) {
    cout << arr[i] << endl;
  }

  return 0;
}
