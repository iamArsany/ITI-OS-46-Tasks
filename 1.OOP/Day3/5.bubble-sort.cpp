#include <iostream>

using namespace std;

int main() {

  int size;
  cout << "size: ";
  cin >> size;

  int arr[size];
  for (int i = 0; i < size; i++) {
    cout << "\nenter num: ";
    cin >> arr[i];
  }

  for (int i = 0; i < size - 1; i++) {
    for (int j = i + 1; j < size; j++) {
      if (arr[j] < arr[i]) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }
  }

  cout << "array: \n";

  for (int i = 0; i < size; i++) {
    cout << arr[i] << " " << endl;
  }
}
