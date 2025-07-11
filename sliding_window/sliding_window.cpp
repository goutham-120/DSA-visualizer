#include<iostream>
#include<vector>
#include "consoleUtils.h"
#include<string>
using namespace std;
namespace Sliding_Window{
struct step{
    int currindex;
    int currstart;
    int currend;
    int maxstart;
    int maxend;
    int currsum;
    int maxsum;
    string st1;
    string st2;
};
void reset(vector<int>& nums,int& k){

    gotoxy(0,0);
    cout<<green<<"----> resetting array and subarray size.....\n\n";
    nums.clear();
    int n,p;
    cout<<yellow<<"enter your new array size: ";
    cin>>n;
    nums.resize(n);
    cout<<yellow<<"\nenter the array elements:\n";
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    cout<<"\nenter new subarray size: ";
    cin>>p;
    k=p;
}

void display(vector<int> nums,int currindex,int currstart,int currend,int maxstart,int maxend,int currsum,int maxsum,string str1,string str2){
    cout<<"array: [ ";
    for(int i=0;i<nums.size();i++){
        if(i==currstart){
            cout<<red;
            cout<<"[ ";
        }
        if(i==currindex) cout<<yellow;
        else if(i>=currstart&&i<=currend) cout<<red;
        else cout<<white;
        cout<<nums[i]<<" ";
        if(i==currend){
            cout<<red;
            cout<<"] ";
            cout<<white;
        }
    }
    cout<<" ]          "<<yellow<<"subarray size -> k = "<<currend-currstart+1<<endl<<endl;
    cout<<purple;
    cout<<"currsum       ";
    cout<<red;
    cout<<"= [ ";
    for(int i=currstart;i<=currend;i++){
        cout<<nums[i]<<" ";
    }
    cout<<"] = "<<currsum<<"    ";
    cout<<yellow;
    cout<<str1<<endl;
    cout<<purple;
    cout<<"maximum so far";
    cout<<green;
    cout<<"= [ ";
    for(int i=maxstart;i<=maxend;i++){
        cout<<nums[i]<<" ";
    }
    cout<<"] = "<<maxsum<<"    ";
    cout<<yellow;
    cout<<str2<<endl;
    cout<<white;
}
void slidingwindow(vector<int> nums,int k){
    vector<step> steps;
    string str1,str2;
    int currsum=0,maxsum=0,maxend=0,maxstart=0;
    for(int i=0;i<k;i++){
        currsum+=nums[i];
    }
    maxsum=currsum;
    maxstart=0;
    maxend=k-1;
    str1="-> starting with a window of size "+to_string(k)+" from "+to_string(nums[0])+" to "+to_string(nums[k-1]);
    str2="-> lets say the current window has the maximum sum ->currsum = maxsum = "+to_string(maxsum);
    steps.push_back({k-1,0,k-1,0,k-1,currsum,maxsum,str1,str2});
    for(int i=k;i<nums.size();i++){
        currsum=currsum+nums[i]-nums[i-k];
         str1="-> checked window sum starting from "+to_string(nums[i-k+1])+" to "+to_string(nums[i]);
         str2="-> maxsum didnt change, as still maxsum{"+to_string(maxsum)+"} >= currsum{"+to_string(currsum)+"}";
        if(currsum>maxsum){
            str2="-> as currsum{"+to_string(currsum)+"} > maxsum{"+to_string(maxsum)+"} updating maxsum -> maxsum = "+to_string(currsum);
             maxsum=currsum;
            maxend=i;
            maxstart=i-k+1;
         }
        steps.push_back({i,i-k+1,i,maxstart,maxend,currsum,maxsum,str1,str2});
    }
    int stepptr=0;
    while(1){
         gotoxy(0,0);
         cout<<green<<"\n\n------> SLIDING WINDOW VISUALIZATION <------\n\n"<<white;
         cout<<green<<"Q) Find maximum sum of subarray of size k in a array:"<<purple<<" similar to LC question : 643\n\n";
          cout<<cyan;
          cout<<"press 'n' for next step\n'p' for previous step\n'q' to quit\n'r' to reset array\n\n";
          cout<<red;
          cout<<"->currsum is the sum of elements inside the current window (subarray) which is RED\n";
          cout<<"->maxsum is the observed maximum currsum so far \n ";
          cout<<"->yellow number is our current indexed number being processed\n\n";
          cout<<white;
          cout<<"step : "<<stepptr+1<<"/"<<steps.size()<<endl<<endl;
          step s=steps[stepptr];
          display(nums,s.currindex,s.currstart,s.currend,s.maxstart,s.maxend,s.currsum,s.maxsum,s.st1,s.st2);
          char ch=_getch();
          if(ch=='n'||ch=='N'){
            if(stepptr<steps.size()-1) stepptr++;
          }
          else if(ch=='p'||ch=='P'){
            if(stepptr>0) stepptr--;
          }
          else if(ch=='r'||ch=='R'){
            reset(nums,k);
            slidingwindow(nums,k);
          }
          else if(ch=='q'||ch=='Q'){
            cout<<green<<"\n\n-->sliding window visualization completed<--\n\ntip: you can try a new array with a new window size!! just press 'r' ,press 'q' to quit \n";
           cout<<white;
            while(1){
                char ch=_getch();
                 if(ch=='r'||ch=='R'){
                    reset(nums,k);
                    slidingwindow(nums,k);
                 }
                  else if(ch=='q'||ch=='Q'){
                     return;
                  }
            }
          }
    }
    return ;
}
void run(){
    vector<int> nums={1,4,2,10,23,3,1,0,20};
    int windowsize=4;
    slidingwindow(nums,windowsize);
 }
}