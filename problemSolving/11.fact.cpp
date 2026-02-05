#include <iostream>

using namespace std;

long long factorial(long long x) {
  if (x == 1)
    return 1;
  return x * factorial(x - 1);
}

int main() {
  int N;
  cin >> N;

  int x;
  for (int i = 0; i < N; i++) {
    cin >> x;
    if (x == 0) {
      cout << 1 << endl;
      continue;
    }

    cout << factorial((long long)x) << endl;
  }
  return 0;
}
