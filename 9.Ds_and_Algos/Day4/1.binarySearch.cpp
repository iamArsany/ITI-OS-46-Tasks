#include <iostream>
using namespace std;

class BinarySearch {
public:
  int *arr;
  int length;

public:
  BinarySearch(int a[], int s) {
    arr = a;
    length = s;
    sortArr();
  }

  int search(int num) {
    int low = 0;
    int high = length - 1;

    while (low <= high) {
      int mid = (low + high) / 2;
      if (arr[mid] == num) {
        return mid;
      } else if (num > arr[mid]) {
        low = mid + 1;
      } else if (num < arr[mid]) {
        high = mid - 1;
      }
    }
    return -1;
  }

private:
  void sortArr() {
    for (int i = 0; i < length - 1; i++) {
      for (int j = i + 1; j < length; j++) {
        if (arr[j] < arr[i]) {
          int temp = arr[i];
          arr[i] = arr[j];
          arr[j] = temp;
        }
      }
    }
  }
};

int main() {
  int arr[] = {1, 2, 3, 8, 10, 20};
  BinarySearch *bs = new BinarySearch(arr, 6);
  cout << bs->search(20);

  return 0;
}
