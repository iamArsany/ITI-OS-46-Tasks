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

  for (int i = 0; i < size; i++) {
    int min = i;
    for (int j = i; j < size; j++) {
      if (arr[min] >= arr[j]) {
        min = j;
      }
    }
    swap(arr[i], arr[min]);
  }

  for (int i = 0; i < size; i++) {
    cout << arr[i] << endl;
  }
}
