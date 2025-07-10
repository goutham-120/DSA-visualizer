#include<iostream>
#include<string>
#include<vector>
#include "consoleUtils.h"
#include<stack>
using namespace std;
namespace recursion{
struct step{
    int level;
    vector<int> curr;
    vector<vector<int>> ans;
    string st;
    string st1;
    string st2;
    string st3;
};
void reset(vector<int>& nums){
    gotoxy(0,0);
    cout<<green<<"----> resetting array....\n\n";
    nums.clear();
    int n;
    cout<<yellow<<"enter your new set size: "<<white;
    cin>>n;
    nums.resize(n);
    cout<<green<<"\nenter the set elements:\n"<<white;
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
}
void displaysubsets(vector<int> nums,int ind,vector<int> curr,vector<vector<int>> ans,string st,string st1,string st2,string st3){
   cout<<red<<"our set : [ ";
   for(int i=0;i<nums.size();i++){
    cout<<nums[i]<<" ";
   }
   cout<<"]     "<<yellow<<st<<"\n\n\n";
   cout<<cyan<<"our current set: [ ";
   for(int i=0;i<curr.size();i++){
      cout<<curr[i]<<" ";
   }
   cout<<"]      "<<yellow<<st1<<"\n\n\n";
   cout<<green<<"our power set: [ ";
   for(auto i:ans){
        cout<<"[ ";
       for(int j:i){
        cout<<j<<" ";
       }
       cout<<"] ";
   }
   cout<<"]    "<<yellow<<st3;
}
void allsubsets(int i,vector<int> nums,vector<int>& curr,vector<vector<int>>& ans,vector<step>& steps,string st,string st1,string st2,string st3){
       st="-> we are at level: "+to_string(i);
       if(i==nums.size()){
        ans.push_back(curr);
        st3="-> as we reached the max level,pushed our current set into power set";
        st1="";
        steps.push_back({i,curr,ans,st,st1,st2,st3});
        return;
       }
       else{
         st3="-> still didnt reach level "+to_string(nums.size());
       }
       curr.push_back(nums[i]);
       st1="-> pushed element at index "+to_string(i)+" ,lets move to next level using recursion..";
       steps.push_back({i,curr,ans,st,st1,st2,st3});
       allsubsets(i+1,nums,curr,ans,steps,st,st1,st2,st3);
       
       st1="-> popped the previous pushed value (back track) and lets move to next level(recursively) without pushing it";
       curr.pop_back();
       steps.push_back({i,curr,ans,st,st1,st2,st3});
       allsubsets(i+1,nums,curr,ans,steps,st,st1,st2,st3);

}
void subsets(vector<int> nums){
    string st1,st2,st3,st;
    st1="-> lets use an array to track subsets";
    st2="-> we will use recursion to reach higher levels and backtracking to come back to previous level recursively";
    st3="-> we will push our current subset into our power set if it reaches it max level\nNOTE: max level means set size";
    
 int n=nums.size();
 st="-> as size is "+to_string(n)+" there will be "+to_string(n)+" levels,we are currently at level 0";
vector<step> steps;
 vector<vector<int>> ans;
 vector<int> curr;
 int i=0;
 steps.push_back({i,curr,ans,st,st1,st2,st3});
 allsubsets(i,nums,curr,ans,steps,st,st1,st2,st3);
     int stepptr=0;
    while(1){
        gotoxy(0,0);
        cout<<green<<"\n\n-----> RECURSION-BACKTRACKING VISUALIZER <-----\n\n";
        cout<<"Q) Find the power set of the given array: "<<red<<"LC question - 78\n\n";
        cout<<cyan;
        cout<<"press : 'n' for next step\n'p' for previous step\n'q' to quit\n'r' for resetting the current array\n\n";
        cout<<purple<<"step: "<<stepptr+1<<"/"<<steps.size()<<"\n\n";
        step s=steps[stepptr];
        displaysubsets(nums,s.level,s.curr,s.ans,s.st,s.st1,s.st2,s.st3);
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
            subsets(nums);
        }
        else if(ch=='q'||ch=='Q'){
            cout<<green<<"\n\n---> backtracking and recursion visualization completed  <----\n\n";
            cout<<yellow<<"if you want to use different array now ,press 'r' or press again 'q' to exit\n";
           cout<<white;
           while(1){
            char ch=_getch();
             if(ch=='r'||ch=='R'){
                reset(nums);
                subsets(nums);
             }
             else if(ch=='q'||ch=='Q') return;
        }
    
    }
   
 }
}
void run(){
    vector<int> nums={1,2,4};
     subsets(nums);
  }
}