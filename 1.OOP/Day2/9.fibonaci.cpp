#include <iostream>
using namespace std;

int main(){
  int i1=0,i2=1,num,prev,search;

  cout<<"Enter number of Series you want to create: ";
  cin>>num;
  cout<<"\nSearch on: ";
  cin>>search;

  cout<<"0"<<endl;
  if(num==1) return 0;
  cout<<"1"<<endl;

  int index=2;
  bool isExist=false;
  for(int i=0;i<num-2;i++){
   cout<< i1 + i2<<endl;
   if(i1+i2==search){
    isExist=true;
     index=i+2;
   }
   prev=i2;
    i2+=i1;
    i1=prev;
  }

  if(isExist){
    printf("\nFound it on index %d",index);
  }else{

    printf("the number you entered don't exist");
  }
}
