#include <iostream>
using namespace std;

int main(){
  char x;
  cout<<"Enter your char: ";
  cin>>x;

  int num=x;
  if(x>=65 && x<91){
    cout<<"This is a capital letter";
  }else if(x>=97 && x<123){
    cout<<"this is a Small letter";
  }else{
    cout<<"this is not a letter";
  }


  return 0;
}
