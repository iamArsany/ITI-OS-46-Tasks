#include <iostream>

using namespace std;

int main() {
  int size;
  cout << "How many numbers you want to enter?\n";
  cin >> size;

  int arr[size] = {0};
  for (int i = 0; i < size; i++) {
    printf("\nEnter number %d: ", i + 1);
    cin >> arr[i];
  }

  int max = 0, num;
  for (int i = 0; i < size - 1; i++) {
    for (int j = 1; j < size; j++) {
      if (arr[i] == arr[j]) {
        if (j - i > max) {
          max = j - i;
          num = arr[i];
        }
      }
    }
  }
  if (max) {
    cout << "Found Max for number " << num << " and max : " << max - 1;
  } else {
    cout << "No numbers matched!";
  }

  return 0;
}
