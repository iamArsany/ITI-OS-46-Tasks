#include <iostream>

using namespace std;
int recBs(int *arr, int target, int low, int high) {
  int mid = (low + high) / 2;
  if (low <= high) {
    if (arr[mid] == target) {
      return mid;
    } else if (target >= arr[mid]) {
      return recBs(arr, target, mid + 1, high);
    } else if (target <= arr[mid]) {
      return recBs(arr, target, low, mid - 1);
    }
  }
  return -1;
}

int bs(int *arr, int s, int target) { return recBs(arr, target, 0, s - 1); }

int main() {
  int arr[] = {1, 2, 10, 20, 23};
  cout << bs(arr, 5, 23);
}
