#include <cstring>
#include <iostream>

using namespace std;

class String {
  int size;
  char *arr;

public:
  String(int _size = 20) {
    size = _size;
    arr = new char[size];
    arr[0] = '\0';
  }

  String(char *str) {
    size = strlen(str) + 1;
    arr = new char[size];
    strcpy(arr, str);
  }
  String(String &str) {
    size = str.size;
    arr = new char[size];
    for (int i = 0; i < size; i++) {
      arr[i] = str.arr[i];
    }
  }
  String operator=(String str) {
    size = str.size;
    arr = new char[size];
    strcpy(arr, str.arr);
    return *this;
  }

  String operator+(String str) {
    int newSize = strlen(arr) + strlen(str.arr) + 1;
    String result(newSize);
    strcpy(result.arr, arr);
    strcat(result.arr, str.arr);
    return result;
  }
  bool operator==(const String &str) { return strcmp(arr, str.arr) == 0; }
  bool operator!=(const String &str) { return !(*this == str); }
  bool operator>(const String &str) { return strcmp(arr, str.arr) > 0; }
  bool operator<(const String &str) { return strcmp(arr, str.arr) < 0; }

  void toUpper() {
    for (int i = 0; arr[i] != '\0'; i++) {
      if (arr[i] >= 'a' && arr[i] <= 'z') {
        arr[i] -= 32;
      }
    }
  }

  void toLower() {
    for (int i = 0; arr[i] != '\0'; i++) {
      if (arr[i] >= 'A' && arr[i] <= 'Z') {
        arr[i] += 32;
      }
    }
  }

  void print() { cout << "\nString: " << arr << endl; }
};

int main() {
  char arr[] = "asdf";
  String s(arr);
  String s2(5);
  s2 = s;
  s2.print();
}
