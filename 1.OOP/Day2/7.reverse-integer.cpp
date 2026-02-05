#include <iostream>

using namespace std;

int main(){
int num,rev=0,pow=1;

printf("Enter Number: ");
cin>>num;

//1255
while (num){
 int rem=num%10;
 rev=rev*10+rem;
 num/=10;
}
cout<<rev;
}
