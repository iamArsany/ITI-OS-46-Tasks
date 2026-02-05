#include <iostream>

using namespace std;

int main(){

  int sum=0,input,num;

  cout<<"How many numbers you want to sum? \n";
  cin>>input;

  for(int i=1;i<=input;i++){
  cout<<"Enter number "<<i<<": " ;
  cin>>num;
  sum+=num;
  }

  cout<<"\n\nSummation : "<<sum;

  return 0;
}
