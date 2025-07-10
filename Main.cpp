#include<iostream>
#include "consoleUtils.h"
using namespace std;
namespace Sliding_Window{void run();}
namespace kadane{void run();}
namespace prefix{void run();}
namespace twopointer{void run();}
namespace recursion{void run();}
namespace binarysearch{void run();}
namespace monotonicstack{void run();}
int main(){
    int choice;
     while(1){
      gotoxy(0,0);
       cout<<yellow<<"\n\n------> WELCOME TO CODEFLOW DSA VISUALIZER <---------\n\n\n";
       cout<<cyan<<"CHOOSE YOUR VISUALIZER\n\n"<<green;
       cout<<"1. SLIDING WINDOW VISUALIZER\n\n2. KADANES VISUALIZER\n\n3. TWO POINTER METHOD VISUALIZER\n\n4. RECURSION-BACKTRACKING VISUALSIZER\n\n5. MONOTONIC STACK VISUALIZER\n\n6. BINARY SEARCH ON ANSWER VISUALIZER\n\n7. PREFIX SUM VISUALIZER\n\n"<<white;
       cout<<"8. EXIT\n\n";
       cout<<"enter your choice: ";
      cin>>choice;
      switch(choice){
        case 1:
           Sliding_Window::run();
           break;
        case 2:
           kadane::run();
           break;
        case 3:
           twopointer::run();
           break;
        case 4:
           recursion::run();
           break;
        case 5:
           monotonicstack::run();
           break;
        case 6:
           binarysearch::run();
           break;
        case 7:
           prefix::run();
         case 8:
            cout<<red<<"EXITING...\n\n";
            exit(0);
         break;
      }
   }
}



