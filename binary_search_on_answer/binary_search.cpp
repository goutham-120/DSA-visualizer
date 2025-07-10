#include<iostream>
#include<string>
#include<vector>
#include "consoleUtils.h"
#include<algorithm>
using namespace std;
namespace binarysearch{
struct step{
     long long low;
     long long high;
     long long mid;
     long long ans;
     int p;
};
void reset(vector<int>& nums,int& key){
    gotoxy(0,0);
    cout<<green<<"----> resetting array and time limit....\n\n";
    nums.clear();
    int n;
    cout<<yellow<<"enter your new array size: "<<white;
    cin>>n;
    nums.resize(n);
    cout<<yellow<<"\nenter the array elements:\n"<<white;
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    cout<<yellow<<"\nenter new time limit: "<<white;
    cin>>key;
}
void displaybinary(vector<int> nums,int hours,int low,int high,int mid,int ans,int& p){
    int Mid=(low+high)/2;
    cout<<red;
     cout<<"piles of bananas :[ ";
    int t=0,tot=0;
    for(int i=0;i<nums.size();i++){
        cout<<nums[i]<<" ";
    }
    cout<<"]\n\n";
    cout<<yellow;
     if(p==0){
        cout<<"-> lets assume lowest speed is 1 and highest is the max num in the array\n(because if koko can eat highest num of bananas with that speed then remaining bananas can definitely be finished)\n also assume our answer speed is the highest speed\n";  
     }
     cout<<red;
    cout<<"\nanswer range: ["<<low<<","<<high<<"]\n";
    cout<<cyan<<"lets check its mid as answer : "<<Mid<<"\n";
    cout<<red<<"\n\nif speed is "<<Mid<<" time taken to eat each pile is: [ ";
    for(int i=0;i<nums.size();i++){
          t+=(nums[i]+Mid-1)/Mid;
          cout<<t<<" ";
          tot+=t;
          t=0;
    }
    cout<<"] = "<<tot<<"\n\n";
    if(tot<=hours){
        ans=Mid;
        cout<<yellow<<"-> as it took "<<tot<<" hours to eat all bananas which is less/equal to "<<hours<<", "<<Mid<<" is a valid speed\n";
       if(Mid-1>=low) cout<<purple<<"lets check if lesser speed is possible: that means checking from "<<low<<" to "<<Mid-1<<" (left half)\n\n";
       else cout<<purple<<" lesser speed is not possible as its already checked\n";
    }
    else{ 
    cout<<yellow<<"-> as it took "<<tot<<" hours to eat all bananas which is greater than "<<hours<<", "<<Mid<<" is not a valid speed\n";
    if(Mid+1<=high) cout<<purple<<"-> so we have to inrease speed as to eat in lesser time: that means checking from "<<Mid+1<<" to "<<high<<" (right half)\n\n";
    else cout<<purple<<"-> speed cant be increased furthur as its already checked\n\n";
    }
    cout<<green<<"-> valid answer till now: "<<ans<<white;
}
bool check(int k,vector<int> nums,int h){
       int total=0;
       for(int i:nums){
          total+=(i+k-1)/k;
       }
       return total<=h;
}
void binarysearch(vector<int> nums,int hours){
    int p=0;
    int n=nums.size();
    vector<step> steps;
    long long high=*max_element(nums.begin(),nums.end()),low=1;
    long long ans=high;
  steps.push_back({low,high,-1,ans,p});
  p=1;
    while(low<=high){
        int mid=(low+high)/2;
        if(check(mid,nums,hours)){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
        if(low>high) break;
           steps.push_back({low,high,mid,ans,p});
    }
    int stepptr=0;
    while(1){
        gotoxy(0,0);
        cout<<green<<"\n\n-----> BINARY SEARCH ON ANSWER VISUALIZER <------\n\n";
        cout<<"Q) Given piles of bananas in an array and integer h, find the minimum integer speed such that all bananas can be heaten in h hours\n"<<red<<"LC question - 875";
        cout<<cyan;
        cout<<"\n\npress : 'n' for next step\n'p' for previous step\n'q' to quit\n'r' for resetting the current array\n\n";
        cout<<red<<"step: "<<stepptr+1<<"/"<<steps.size()<<"\n";
        step s=steps[stepptr];
         displaybinary(nums,hours,s.low,s.high,s.mid,s.ans,s.p);
         char ch=_getch();
        if(ch=='n'||ch=='N'){
           if(stepptr<steps.size()-1) stepptr++;
        }
        else if(ch=='p'||ch=='P'){
            if(stepptr>0) stepptr--;
        }
        else if(ch=='r'||ch=='R'){
            reset(nums,hours);
            gotoxy(0,0);
            binarysearch(nums,hours);
        }
        else if(ch=='q'||ch=='Q'){
            cout<<green<<"\n\n----> prefix sum visualization completed! <----\n\n";
            cout<<yellow<<"if you want to use different number of bananas and time ,press 'r' or press again 'q' to exit\n";
          cout<<white;
           while(1){
            char ch=_getch();
             if(ch=='r'||ch=='R'){
                reset(nums,hours);
                binarysearch(nums,hours);
             }
             else if(ch=='q'||ch=='Q') return;
        }
    
    }
   
 }
}
void run(){
    vector<int> nums={30,11,23,4,20};
    int key=6;
    binarysearch(nums,key);
   }
}