#include <iostream>
#include <stdio.h>

using namespace std;

int main(){

  int wordCount=1,charCount=0;
  char ch;
  cout<<"Enter your Sentence:\n";
  while(cin.get(ch)){

  if(ch=='\n'){
    break;
  }
    switch (ch)
    {
      case(' '):
        wordCount++;
        break;
      default:
        charCount++;
        break;
    }
  }
    cout<<"Words count: "<<wordCount<<endl;
    cout<<"Charcters count: "<<charCount<<endl;
return 0;
 }

