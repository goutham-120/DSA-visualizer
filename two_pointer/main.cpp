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
    vector<int> res;
    int left;
    int right;
    string st;
    int f;
};
void gotoxy(int x,int y){
    cout<<"\033["<<x<<";"<<y<<"H";
}
void clear(){
    cout<<"\033[2J\033[H";
}
void reset(vector<int>& nums,int& target){
    clear();
    nums.clear();
    cout<<"resetting array.....\n";
    int n;
    int w;
    cout<<cyan;
    cout<<"enter your new array size: ";
    cin>>n;
    nums.resize(n);
    cout<<yellow;
    cout<<"\nenter the array elements:\n";
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    cout<<green;
    cout<<"enter new target: ";
    cin>>w;
    target=w;
    sort(nums.begin(),nums.end());
    clear();
}
void displaytwoptr(vector<int> nums,vector<int> result,int left,int right,string str,int target,int f){
         cout<<cyan<<"sorted array: ";
         cout<<white<<"[ ";
         for(int i=0;i<nums.size();i++){
            if(i==left) cout<<red;
            else if(i==right) cout<<cyan;
            else cout<<white;
            cout<<nums[i]<<" ";
         }
         cout<<white<<"]    "<<green<<"target = "<<target<<white;
         cout<<endl<<endl;
        cout<<yellow<<str<<"\n\n";
         cout<<purple<<"left pointer index: "<<left<<green<<"  value: "<<nums[left]<<" "<<endl<<white;
         cout<<purple<<"right pointer index: "<<right<<green<<"  value: "<<nums[right]<<" "<<endl<<endl;
        
         cout<<blue<<"answer: ";
         if(nums[left]+nums[right]==target&&f==1){
            cout<<green<<"matched!!..        ";
         }
         else cout<<red<<"now lets check..   ";
         cout<<"[ "<<nums[left]<<","<<nums[right]<<"  ]\n\n";
        cout<<white;
        
}
void twopointer(vector<int> nums,int target){
     int l=0,r=nums.size()-1,left=0,right=nums.size()-1;
     vector<int> result;
     vector<step> steps;
     int f=0;
     string str="(lets take two pointers: left pointer(red),right pointer(blue))                                 ";
     steps.push_back({result,l,r,str});
     while(l<=r){
        int p=0;
          if(nums[l]+nums[r]==target){
              result.push_back(nums[l]);
              result.push_back(nums[r]);
              left=l;
              right=r;
              f=1;
              str="(their sum{"+to_string(nums[l])+"+"+to_string(nums[r])+"} is equal to the target{"+to_string(target)+"} so found!)                                      ";
          p=1;
          }
          else if(nums[l]+nums[r]<target){
              
              str="(their sum{"+to_string(nums[l])+"+"+to_string(nums[r])+"} was less than target{"+to_string(target)+"} so incremented left pointer to get bigger value)      ";
             l++;
          }
          else{
            str="(their sum{"+to_string(nums[l])+"+"+to_string(nums[r])+"} was bigger than target{"+to_string(target)+"} so decremented right pointer to get smaller value)";
            r--;
          }
          steps.push_back({result,l,r,str,f});
          if(p==1) break;
     }
     int stepptr=0;
     while(1){
        gotoxy(0,0);
        cout<<cyan;
        cout<<"press : 'n' for next step\n'p' for previous step\n'q' to quit\n'r' for resetting the current array\n\n";
        cout<<"step: "<<stepptr+1<<"/"<<steps.size()<<"\n";
        step s=steps[stepptr];
        displaytwoptr(nums,s.res,s.left,s.right,s.st,target,s.f);
         char ch=_getch();
        if(ch=='n'||ch=='N'){
           if(stepptr<steps.size()-1) stepptr++;
        }
        else if(ch=='p'||ch=='P'){
            if(stepptr>0) stepptr--;
        }
        else if(ch=='r'||ch=='R'){
            reset(nums,target);
            gotoxy(0,0);
            twopointer(nums,target);
        }
        else if(ch=='q'||ch=='Q'){
            cout<<"\n\n two pointer method visualization completed!\n\n";
            cout<<"if you want to use different array now ,press 'r' or press again 'q' to exit\n";
           while(1){
            char ch=_getch();
             if(ch=='r'||ch=='R'){
                reset(nums,target);
                twopointer(nums,target);
             }
             else if(ch=='q'||ch=='Q') exit(0);
        }
    
    }
 }
     
}
int main(){
    vector<int> nums={1,2,3,4,5,8};
    int target=7;
    twopointer(nums,target);

}
