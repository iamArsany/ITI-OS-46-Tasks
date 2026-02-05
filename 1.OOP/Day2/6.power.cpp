#include <iostream>

using namespace std;

int main(){
  int num,pow,res=1;

  cout<<"Enter Number: ";
  cin>>num;
  cout<<"Enter Power: ";
  cin>>pow;

  for(int i=0;i<pow;i++){
    res*=num;
  }

  printf("\n %d ^ %d = %d",num,pow,res);
  return 0;
}
