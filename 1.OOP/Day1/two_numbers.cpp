#include<iostream>

using namespace std;

int main(){
  int x,y;
  cout<<"Enter first Number: ";
  cin>>x;
  cout<<"Enter Second Number: ";
  cin>>y;

  cout<<"Addition = "<<x+y;
  cout<<"\nSubstraction = "<<x-y;
  cout<<"\nMultiplication = "<<x*y;
  if(y==0){
  cout<<"\nCannot Divide by 0";
  }else{
  cout<<"\nDivision = "<<x/y;
  }



  return 0;
}


