#include <iostream>

using namespace std;

int main() {
  int arrNum, elemNum;
  cout << "Number of Arrays: ";
  cin >> arrNum;
  cout << "Number of Elements: ";
  cin >> elemNum;
  int arr[arrNum][elemNum] = {0};

  for (int i = 0; i < arrNum; i++) {
    cout << "Array " << i + 1 << ": \n";
    for (int j = 0; j < elemNum; j++) {
      printf("Enter number %d: ", j + 1);
      cin >> arr[i][j];
    }
  }

  int sum = 0;
  int sumArr[arrNum] = {0};

  for (int i = 0; i < arrNum; i++)
    , arr[i][j] {
      for (int j = 0; j < elemNum; j++) {
        sum += arr[i][j];
      }
      sumArr[i] = sum;
      sum = 0;
    }

  float avgArr[elemNum] = {0};
  float avg = 0;

  for (int i = 0; i < elemNum; i++) {
    for (int j = 0; j < arrNum; j++) {
      avg += arr[j][i];
    }
    avgArr[i] = avg / arrNum;
    avg = 0;
  }

  cout << "Sum: ";
  for (int i = 0; i < arrNum; i++) {
    printf("\nSum for arr %d : %d", i + 1, sumArr[i]);
  }
  cout << "\n\navg: ";
  for (int i = 0; i < elemNum; i++) {
    printf("\navg for Column %d : %0.2f", i + 1, avgArr[i]);
  }

  cout << "\n\n Array: ";
  for (int i = 0; i < arrNum; i++) {
    cout << "\n";
    for (int j = 0; j < elemNum; j++) {
      printf(" %d  ", arr[i][j]);
    }
  }
  return 0;
}
