#include <iostream>

using namespace std;

int main(){
  char x;
  cout<<"Enter the Char: ";
  cin>>x;

  int dec=x;

  string res;
  int num;
  while(dec!=0){
    num=dec%16;
    cout<<num<<endl;
    dec/=16;

  }

  return 0;
}
