#include <iostream>

using namespace std;

int main(){
  cout<<"Enter your degree: ";
  int degree;
  cin>>degree;

  if(degree>=90){
    cout<<"Excellent!";
  }else if(degree>=80){
    cout<<"Very Good!";
  }else if(degree>=65){
    cout<<"Good!";
  }else if(degree>=50){
    cout<<"Pass";
  }else {
    cout<<"Failed";
  }

  return 0;
}
