#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<conio.h>
using namespace std;

#define red "\033[31m"
 #define green "\033[32m"
 #define yellow "\033[33m"
 #define blue "\033[34m"
#define purple "\033[35m"
#define cyan "\033[36m"
#define white "\033[37m"

struct step{
     int currindex;
     vector<int> prefix;
     string st;
};
void gotoxy(int x,int y){
    cout<<"\033["<<x<<";"<<y<<"H";
}
void clear(){
    cout<<"\033[2J\033[H";
}

void reset(vector<int>& nums){
    system("cls");
    nums.clear();
    int n;
    cout<<"enter your new array size: ";
    cin>>n;
    nums.resize(n);
    cout<<"\nenter the array elements:\n";
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    clear();
}
void display(vector<int> nums,int currindex,vector<int> prefix,string st){
    cout<<white;
     cout<<"given array: [ ";
     cout<<red;
     cout<<"[";
     for(int i=0;i<nums.size();i++){
        if(i==currindex){
            cout<<yellow;
            cout<<nums[i];
            cout<<red;
            cout<<"] ";
            cout<<white;
        }
        else{
            cout<<nums[i]<<" ";
        }
   }
   cout<<"]";
   cout<<green;
   cout<<"\n\nprefix sum array: ";
   for(int i=0;i<prefix.size();i++){
       if(i==currindex){
        cout<<yellow;
        cout<<prefix[i]<<" ";
       }
       else if(i>currindex+1){
        cout<<blue;
          cout<<"_ ";
       }
       else{
        cout<<white;
        cout<<prefix[i]<<" ";
       }
 }
 cout<<"\n\n";
  cout<<yellow;
 cout<<st;
  cout<<white;
}
void prefixsum(vector<int> nums){
    vector<step> steps;
    int n=nums.size();
    vector<int> prefix(n+1,0);
    string str;
    for(int i=0;i<n;i++){
        prefix[i+1]=prefix[i]+nums[i]; 
         if(i==0){
        str="prefix[0] is initialised to zero as base case and prefix[1] = prefix[0]+nums[0]";
        }
        if(i>0){
            str="prefix["+to_string(i+1)+"] = sum of curr element{"+to_string(nums[i])+"} and its prefix sum{"+to_string(prefix[i])+"} = "+to_string(prefix[i+1])+"                              ";
        }
        steps.push_back({i,prefix,str});
    }
    int stepptr=0;
    while(1){
        gotoxy(0,0);
       
        cout<<cyan;
        cout<<"press : 'n' for next step\n'p' for previous step\n'q' to quit\n'r' for resetting the current array\n\n";
        cout<<"step: "<<stepptr+1<<"/"<<steps.size()<<"\n";
        step s=steps[stepptr];
        display(nums,s.currindex,s.prefix,s.st);
         char ch=_getch();
        if(ch=='n'||ch=='N'){
           if(stepptr<steps.size()-1) stepptr++;
        }
        else if(ch=='p'||ch=='P'){
            if(stepptr>0) stepptr--;
        }
        else if(ch=='r'||ch=='R'){
            reset(nums);
            gotoxy(0,0);
            prefixsum(nums);
        }
        else if(ch=='q'||ch=='Q'){
            cout<<"\n\n prefix sum visualization completed!\n\n";
            cout<<"if you want to use different array now ,press 'r' or press again 'q' to exit\n";
           while(1){
            char ch=_getch();
             if(ch=='r'||ch=='R'){
                reset(nums);
                prefixsum(nums);
             }
             else if(ch=='q'||ch=='Q') exit(0);
        }
    
    }
   
 }
 return;
}
int main(){
    vector<int> nums={1,2,3,4,5,6,7};
    prefixsum(nums);
    return 0;

}