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

  // Printing
  cout << "Printing Numbers:\n";
  for (int i = 0; i < size; i++) {
    printf("arr[%d]=%d\n", i, arr[i]);
  }

  // summation
  int sum = 0;
  for (int i = 0; i < size; i++) {
    sum += arr[i];
  }
  cout << "\nSummation: " << sum;

  // max and min
  int max = arr[0], min = arr[0];
  for (int i = 1; i < size; i++) {
    if (arr[i] > max)
      max = arr[i];
    if (arr[i] < min)
      min = arr[i];
  }
  cout << "\nMax: " << max;
  cout << "\nMin: " << min << endl;

  // serach
  int input;
  cout << "Enter number to search: ";
  cin >> input;
  bool isFound = false;
  for (int i = 0; i < size; i++) {
    if (arr[i] == input) {
      printf("Found %d at %d\n", input, i + 1);
      isFound = true;
    }
  }
  if (!isFound)
    cout << "Not Found";
}
