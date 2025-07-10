#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
#include "consoleUtils.h"
namespace prefix{
struct step{
     int currindex;
     vector<int> prefix;
     string st;
};
void reset(vector<int>& nums){
    gotoxy(0,0);
    nums.clear();
    int n;
    cout<<green<<"----> changing array... <----\n\n";
    cout<<yellow;
    cout<<"enter your new array size: "<<white;
    cin>>n;
    nums.resize(n);
    cout<<yellow<<"\nenter the array elements:\n"<<white;
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
}
void display(vector<int> nums,int currindex,vector<int> prefix,string st){
    cout<<cyan;
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
            cout<<white;
            cout<<nums[i]<<" ";
        }
   }
   cout<<cyan<<"]";
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
        cout<<green<<"\n\n-----> PREFIX SUM VISUALIZATION <------\n\n";
        cout<<"Q) Find the running sum of each element upto its index in an array "<<red<<"similar LC question - 1480\n\n";
        cout<<cyan;
        cout<<"press : 'n' for next step\n'p' for previous  step\n'q' to quit\n'r' for resetting the current array\n\n";
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
            cout<<green<<"\n\n---> prefix sum visualization completed! <-----\n\n";
            cout<<"if you want to use different array now ,press 'r' or press again 'q' to exit\n";
           cout<<white;
           while(1){
            char ch=_getch();
             if(ch=='r'||ch=='R'){
                reset(nums);
                prefixsum(nums);
             }
             else if(ch=='q'||ch=='Q') return;
        }
    
    }
   
 }
 return;
}
void run(){
    vector<int> nums={1,2,3,4,5,6,7};
    prefixsum(nums);
  }
}