#include <iostream>
#include <vector>

using namespace std;

void swap(int &x, int &y) {
  int tmp = x;
  x = y;
  y = tmp;
}
vector<int> partition(vector<int> arr, int low, int high) {
  int pivot = high, currentIdx = low + 1;
  cout << "pivot" << pivot << endl;
  cout << "pivot" << currentIdx << endl;
  if (high - low == 0 || high - low == 1)
    return arr;
  cout << "here in the partition" << endl;
  while (low != high) {
    if (arr[currentIdx] > arr[pivot]) {
      swap(arr[low], arr[currentIdx]);
      currentIdx++;
    }
    swap(arr[pivot], arr[currentIdx]);
  }
  partition(arr, low, pivot - 1);
  partition(arr, pivot + 1, high);
  return arr;
}
vector<int> quickSort(vector<int> arr) {
  int low = 0, high = arr.size();
  return partition(arr, low, high);
}

int main() {
  vector<int> arr = {2, 1, 10, 3, 7, 29, 13};
  int size = arr.size();

  quickSort(arr);

  for (int i = 0; i < size; i++) {
    cout << arr[i] << endl;
  }
}
