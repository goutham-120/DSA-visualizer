#include<iostream>
#include<string>
#include<vector>
#include "consoleUtils.h"
#include<stack>
using namespace std;
namespace monotonicstack{
struct step{
    int currindex;
    int top;
    vector<int> ans;
    string str1;
    string str2;
    string str3;
    string str4;
     vector<int> st;
};
void reset(vector<int>& nums){
    gotoxy(0,0);
    cout<<green<<"----> resetting temperatures....\n\n";
    nums.clear();
    int n;
    cout<<yellow<<"enter your new array size: "<<white;
    cin>>n;
    nums.resize(n);
    cout<<yellow<<"\nenter the array elements:\n"<<white;
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
}
void displaystack(vector<int> nums,int currindex,int top,vector<int> ans,string str1,string str2,string str3,string str4,vector<int> st){
    cout<<red<<"array: [ ";
    int n=nums.size(),m=st.size(),k=ans.size();
    for(int i=0;i<n;i++){
        if(i==currindex) cout<<yellow;
        else cout<<white;
        cout<<nums[i]<<" ";
    }
    cout<<red<<"]\n\n"<<yellow<<str1<<"\n\n";
    cout<<red<<"stack : [ ";
    for(int i=0;i<m;i++){
        if(i==m-2) cout<<yellow;
        else if(i==m-1) cout<<cyan;
        else cout<<white;
        cout<<st[i]<<" ";
    }
    cout<<red<<"]\n\n"<<yellow<<str2<<"\n"<<str3<<"\n\n";
    cout<<green<<"answer: [ ";
    for(int i=0;i<k;i++){
        if(i==currindex) cout<<yellow;
        else cout<<white;
        cout<<ans[i]<<" ";
    }
    cout<<green<<"]\n\n"<<yellow<<str4<<"\n\n";
}
void monotonicstack(vector<int> nums){
    int n=nums.size();
    string str1,str2,str3,str4;
    vector<int> ans(n,0);
    vector<step> steps;
    vector<int> pop;
    str1="-> we start our iteration from last of the array ";
    str2="-> we will use a stack to keep track of indices and pop indices from top if they have lesser/equal value than our current element";
    str3="-> and push the current index into it";
    str4="-> initialising our answer array to 0,{lets say there are no geater temperatures}";
    vector<int> st;  
    steps.push_back({-1,-1,ans,str1,str2,str3,str4,st});
    for(int i=n-1;i>=0;i--){
        str1="->our current index: "+to_string(i);
        if(st.size()==0){
        str2="->didnt pop anything from stack as it was empty ";
        }
        else{
            str2="-> didnt pop anything from stack as index at its top{"+to_string(st.back())+"} corresponds to value{"+to_string(nums[st.back()])+"} > current value {"+to_string(nums[i])+"}";
        }
        while(!st.empty()&&nums[st.back()]<=nums[i]){
             str2="-> popped indices starting from top{"+to_string(st.back())+"} as they correspond to numbers lesser than current{"+to_string(nums[i])+"} until we either found a greater one or stack becomes empty ";
              st.pop_back();
             }

        if(!st.empty()){
            ans[i]=st.back()-i;
            str4="-> we have a greater temperature after "+to_string(ans[i])+" days/day: "+to_string(nums[i])+"->"+to_string(nums[st.back()])+"\n{the top element of stack contained the index{"+to_string(st.back())+"} which corresponds to value{"+to_string(nums[st.back()])+"} > current element{"+to_string(nums[i])+"} (smaller ones were popped) ,so we found difference between their indices->("+to_string(st.back())+"-"+to_string(i)+"="+to_string(ans[i])+")}";
        }
        else{
            str4="-> as stack was empty, it means there was no element which was greater than our current element "+to_string(nums[i]);
        }
        st.push_back(i);
        str3="-> pushed our current index "+to_string(i)+" into stack at end of this step\nNOTE: yellow - current top in each step,blue -  pushed index at end of each step";
        steps.push_back({i,st.back(),ans,str1,str2,str3,str4,st});
    } 
    int stepptr=0;
    while(1){
        gotoxy(0,0);
        cout<<green<<"\n\n------> MONOTONIC STACK VISUALIZATION <-------\n\n";
        cout<<"Q) Given an array of temeratures,return an array that tells how many days you must wait until a warmer temperature for each,if none ,put 0\n";
        cout<<red<<"LC question - 739\n\n";
        cout<<cyan;
        cout<<"press : 'n' for next step\n'p' for previous step\n'q' to quit\n'r' for resetting the current array\n\n";
        cout<<purple<<"step: "<<stepptr+1<<"/"<<steps.size()<<"\n\n";
        step s=steps[stepptr];
        displaystack(nums,s.currindex,s.top,s.ans,s.str1,s.str2,s.str3,s.str4,s.st);
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
            monotonicstack(nums);
        }
        else if(ch=='q'||ch=='Q'){
            cout<<green<<"\n\n---> monotonic stack example visualization completed  <----\n\n";
            cout<<"if you want to use different array now ,press 'r' or press again 'q' to exit\n";
           cout<<white;
           while(1){
            char ch=_getch();
             if(ch=='r'||ch=='R'){
                reset(nums);
                monotonicstack(nums);
             }
             else if(ch=='q'||ch=='Q') return;
        }
    } 
 }
}
void run(){
    vector<int> nums={73,74,75,71,69,72,76};
  monotonicstack(nums); 
  }
}