#include<iostream>
#include<vector>
#include<string>
#include "consoleUtils.h"
using namespace std;
namespace kadane{
struct step{
    int index;
    int tempstart;
    int currsum;
    int maxsum;
    int start;
    int end;
    string st1;
    string st2;
};
void reset(vector<int>& nums){
    gotoxy(0,0);
    nums.clear();
    int n;
    cout<<"enter your new array size: ";
    cin>>n;
    nums.resize(n);
    cout<<"\nenter the array elements:\n";
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
}
void displayArray(vector<int>& nums,int currindex,int currstart,int currend,int currsum,int maxsum,int maxstart,int maxend,string str1,string str2){
     for(int i=0;i<nums.size();++i){
        if(i==currstart){
            cout<<red;
            cout<<"[";
            cout<<white;
        }
        if(i==maxstart){
            cout<<green;
            cout<<"[";
            cout<<white;
        }
        if(i==currindex) {
            cout<<yellow;
        }
        else if(i>=maxstart&&i<=maxend) cout<<green;
        else if(i>=currstart&&i<=currend) cout<<red;
        else cout<<white;
        cout<<nums[i];
        cout<<white;
        cout<<" ";
        if(i==maxend){
            cout<<green;
            cout<<"]";
            cout<<white;
        }
        if(i==currend){
            cout<<red;
            cout<<"]";
            cout<<white;
        }
    }
   
    cout<<white;
        cout<<blue;
        cout<<"\n\ncurrent sum = ";
        cout<<red;
        cout<<"[ ";
        for(int i=currstart;i<=currend;i++){
            cout<<nums[i]<<" ";
        }
        cout<<"] = "<<currsum<<"  ";
        cout<<purple;
        cout<<str1<<endl;
        cout<<white;
        cout<<blue;
        cout<<"\nmaxsum = ";
        cout<<green;
        cout<<"[ ";
        for(int i=maxstart;i<=maxend;i++){
            cout<<nums[i]<<" ";
        }
        cout<<"] = "<<maxsum<<"   ";
        cout<<purple;
        cout<<str2<<endl;
        cout<<white;
    cout<<"\n\n";
}
void displayfinal(vector<int> nums,int s,int e,int m){
         for(int i=0;i<nums.size();i++){
            if(i==s){
                cout<<green;
                cout<<"[";
                cout<<white;
            }
            if(i>=s&&i<=e){
                cout<<green;
                cout<<nums[i]<<" ";
                cout<<white;
            }
            else{
                cout<<nums[i]<<" ";
            }
            if(i==e){
                cout<<green;
                cout<<"] ";
                cout<<white;
            } 
         }
         cout<<blue;
         cout<<endl<<"max sum subarray = ";
         cout<<green;
         cout<<"[";
         for(int i=s;i<=e;i++){
            cout<<nums[i]<<" ";
         }
         cout<<"] = ";
          cout<<blue;
            cout<<m<<endl;
        cout<<white; 
         
    }
    void displayfirst(vector<int> nums,int s){
        cout<<cyan;
       cout<<"step: 0/"<<s<<"\n\n";
       cout<<"Array: ";
       cout<<white;
        for(int i=0;i<nums.size();i++){
            if(i==0){
                cout<<red;
                cout<<"[";
                cout<<green;
                cout<<"[";
                cout<<yellow;
                cout<<nums[i];
                cout<<green;
                cout<<"]";
                cout<<red;
                cout<<"] ";
                cout<<white;
            }
            else{
                cout<<nums[i]<<" ";
            }
        }
         cout<<yellow<<"\n\nstarting with currsum=maxsum="<<nums[0]<<"\n";
        cout<<endl;
    }
void kadaneVisualizer(vector<int> &nums){
    vector<step> steps;
    int maxsum=nums[0];
    int currsum=nums[0];
    int start=0,end=0,tempstart=0;
    int fm=0,fs=0,fe=0,p=0;
    string str1,str2;
    for(int i=1;i<nums.size();i++){
        p=0;
        if(currsum<0){
            str1="-> cursum{"+to_string(currsum)+"} is -ve ,so started currsum newly from "+to_string(nums[i]);
          currsum=nums[i];
            tempstart=i;
            }else{
            str1="-> currsum{"+to_string(currsum)+"} added "+to_string(nums[i])+" to become "+to_string(currsum+nums[i])+" as currsum{"+to_string(currsum)+"} was not -ve";
            currsum+=nums[i];
        }
        if(currsum>maxsum){
            str2="-> currsum{"+to_string(currsum)+"} > maxsum{"+to_string(maxsum)+"} so changed maxsum as currsum {maxsum <- currsum}";
             maxsum=currsum;
             start=tempstart;
            end=i;
            p=1;
        }
        if(p==0){
            str2="-> maxsum didnt change, as maxsum{"+to_string(maxsum)+"} > currsum{"+to_string(currsum)+"}";
        }
        fs=start;
        fe=end;
        fm=maxsum;
        steps.push_back({i,tempstart,currsum,maxsum,start,end,str1,str2});
    }
    int stepptr=-1;
    while(1){
        gotoxy(0,0);
        cout<<green<<"\n\n-----> KADANES ALGORITHM VISUALIZATION <-----\n\n";
        cout<<"Q) Find the maximum subarray sum of a given array where subarray size is not fixed: "<<red<<"LC question - 53\n\n";
        cout<<cyan;
        cout<<"press 'n' for next step\n'p' for previous step\n'q' for final result\n'r' to reset the array\n\n";
       cout<<yellow;
        cout<<"red brackets [] -> current sum\ngreen brackets [] -> max sum so far\nyellow color -> current index value\n\n";
        cout<<white;
        if(stepptr==-1){
            displayfirst(nums,steps.size());
        }
        else{
        step s=steps[stepptr];
        cout<<cyan;
        cout<<"step: "<<stepptr+1<<"/"<<steps.size()<<endl<<endl;
        cout<<"Array : ";
        cout<<white;
           displayArray(nums,s.index,s.tempstart,s.index,s.currsum,s.maxsum,s.start,s.end,s.st1,s.st2);
        }
        char ch=_getch();
        if(ch=='n'||ch=='N'){
            if(stepptr<(int)steps.size()-1) stepptr++;
        }
        else if(ch=='p'||ch=='P'){
            if(stepptr>-1) stepptr--;
        }
         else if(ch=='q'||ch=='Q'){
            cout<<"final result :\n";
          displayfinal(nums,fs,fe,fm);
            cout<<green;
            cout<<"\n\n---> Kadanes algorithm visualization completed  <----\n\n";
            cout<<"if you want to use different array ,press 'r' or press again 'q' to exit\n";
           while(1){
            cout<<white;
            char ch=_getch();
             if(ch=='r'||ch=='R'){
                reset(nums);
                kadaneVisualizer(nums);
             }
             else if(ch=='q'||ch=='Q'){
               return;
             }
        }
    
    }
        
}     
  return ;  
}
int run(){
    vector<int> nums ={-2, 1, -3, 4, -1, 2, 1, -5, 4};
    kadaneVisualizer(nums);
    return 0;
}
}