#include <iostream>
#include <vector>

using namespace std;

void swap(int &x, int &y) {
  int tmp = x;
  x = y;
  y = tmp;
}

int main() {
  vector<int> arr = {2, 1, 10, 3, 7, 29, 13};
  int size = arr.size();

  for (int i = 0; i < size - 1; i++) {
    for (int j = i + 1; j < size; j++) {
      if (arr[j] < arr[j - 1]) {
        swap(arr[j], arr[j - 1]);
      }
    }
  }

  for (int i = 0; i < size; i++) {
    cout << arr[i] << endl;
  }
}
