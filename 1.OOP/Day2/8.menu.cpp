#include <iostream>

using namespace std;

int main(){

  cout<<"(n) New Item \n";
  cout<<"(d) Display \n";
  cout<<"(e) exit \n";
  cout<<"\n\nEnter your Answer: ";


  bool flag=false,isDef=false;
  while(true){

  cout << "\033[2J\033[1;1H"; 
//  cout<<"(n) New Item \n";
 // cout<<"(d) Display \n";
 // cout<<"(e) exit \n";
  cout<<"\n\nEnter your Answer: ";

  if(isDef){
    cout<<"\nPlease try again with valid options: ";
    isDef=false;
  }
  char ch=cin.get();
  cin.ignore(1000,'\n');

 switch(ch){
      case('n'):
      case('N'):
        cout<<"New item has been chosen!\n";
        break;
      case('d'):
      case('D'):
        cout<<"Display Item has been chosen!\n";
        break;

      case('e'):
      case('E'):
        cout<<"Exit!!!";
        flag=true;
        break;
      default:
        isDef=true;
        continue;
    }

    if(flag) break;
    cout<<"\n\nEnter to choose again and Press any key to exit";
  
    char res=cin.get();
    if(res!='\n'){
    return 0; 
    }
  }
return 0;
}


