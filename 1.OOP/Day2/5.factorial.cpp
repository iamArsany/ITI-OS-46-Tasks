#include <iostream>

using namespace std;

int main(){

  int x,fac=1;
  cout<<"enter number: ";
  cin>>x;

  while(x){
   fac*=x; 
   x--;
  }
  cout<<"Factorial: "<<fac;
}

