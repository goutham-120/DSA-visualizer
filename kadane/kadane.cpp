#include<iostream>
#include<vector>
#include<windows.h>
#include<conio.h>
#include<string>
using namespace std;
enum Color {
    GREEN=10,
    RED=4,
    WHITE=15,
    BLUE=3,
    YELLOW=6,
    PINK=12,
};
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
void setColor(int color){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color);
}
void displayArray(vector<int>& nums,int currindex,int currstart,int currend,int currsum,int maxsum,int maxstart,int maxend,string str1,string str2){
     for(int i=0;i<nums.size();++i){
        if(i==currstart){
            setColor(RED);
            cout<<"[";
            setColor(WHITE);
        }
        if(i==maxstart){
            setColor(GREEN);
            cout<<"[";
            setColor(WHITE);
        }
        if(i==currindex) {
            setColor(YELLOW);
        }
        else if(i>=maxstart&&i<=maxend) setColor(GREEN);
        else if(i>=currstart&&i<=currend) setColor(RED);
        else setColor(WHITE);
        cout<<nums[i];
        setColor(WHITE);
        cout<<" ";
        if(i==maxend){
            setColor(GREEN);
            cout<<"]";
            setColor(WHITE);
        }
        if(i==currend){
            setColor(RED);
            cout<<"]";
            setColor(WHITE);
        }
    }
   
    setColor(WHITE);
        setColor(BLUE);
        cout<<"\ncurrent sum = ";
        setColor(RED);
        cout<<"[ ";
        for(int i=currstart;i<=currend;i++){
            cout<<nums[i]<<" ";
        }
        cout<<"] = "<<currsum<<"  ";
        setColor(PINK);
        cout<<str1<<endl;
        setColor(WHITE);
        setColor(BLUE);
        cout<<"maxsum = ";
        setColor(GREEN);
        cout<<"[ ";
        for(int i=maxstart;i<=maxend;i++){
            cout<<nums[i]<<" ";
        }
        cout<<"] = "<<maxsum<<"   ";
        setColor(PINK);
        cout<<str2<<endl;
        setColor(WHITE);
    cout<<"\n\n";
}
void displayfinal(vector<int> nums,int s,int e,int m){
         for(int i=0;i<nums.size();i++){
            if(i==s){
                setColor(GREEN);
                cout<<"[";
                setColor(WHITE);
            }
            if(i>=s&&i<=e){
                setColor(GREEN);
                cout<<nums[i]<<" ";
                setColor(WHITE);
            }
            else{
                cout<<nums[i]<<" ";
            }
            if(i==e){
                cout<<"] ";
            } 
         }
         setColor(BLUE);
         cout<<endl<<"max sum subarray = ";
         setColor(GREEN);
         cout<<"[";
         for(int i=s;i<=e;i++){
            cout<<nums[i]<<" ";
         }
         cout<<"] = ";
          setColor(BLUE);
            cout<<m<<endl;
         setColor(WHITE);  
         
    }
    void displayfirst(vector<int> nums){
       cout<<"step 0: \n\n";
       cout<<"array: ";
        for(int i=0;i<nums.size();i++){
            if(i==0){
                setColor(RED);
                cout<<"[";
                setColor(GREEN);
                cout<<"[";
                setColor(YELLOW);
                cout<<nums[i];
                setColor(GREEN);
                cout<<"]";
                setColor(RED);
                cout<<"] ";
                setColor(WHITE);
            }
            else{
                cout<<nums[i]<<" ";
            }
        }
         cout<<"\nstarting with currsum=maxsum="<<nums[0]<<"\n";
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
            str1="cursum{"+to_string(currsum)+"} was -ve ,so started currsum newly from "+to_string(nums[i]);
          currsum=nums[i];
            tempstart=i;
            }else{
            str1="currsum{"+to_string(currsum)+"} added "+to_string(nums[i])+" to become "+to_string(currsum+nums[i])+" as currsum{"+to_string(currsum)+"} was not -ve";
            currsum+=nums[i];
        }
        if(currsum>maxsum){
            str2="currsum{"+to_string(currsum)+"} > maxsum{"+to_string(maxsum)+"} so updated maxsum {maxsum = currsum}";
             maxsum=currsum;
             start=tempstart;
            end=i;
            p=1;
        }
        if(p==0){
            str2="maxsum didnt change, as maxsum{"+to_string(maxsum)+"} > currsum{"+to_string(currsum)+"}";
        }
        fs=start;
        fe=end;
        fm=maxsum;
        steps.push_back({i,tempstart,currsum,maxsum,start,end,str1,str2});
    }
    int stepptr=-1;
    while(1){
        system("cls");
        cout<<"press 'n' for next step,'p' for previous step and 'q' for final result\n\n";
        setColor(YELLOW);
        cout<<"red brackets []= current sum\ngreen brackets []=max sum so far\nyellow color=current index\n\n";
        setColor(WHITE);
        if(stepptr==-1){
            displayfirst(nums);
        }
        else{
        step s=steps[stepptr];
        cout<<"step: "<<stepptr+1<<"/"<<steps.size()<<endl;
        cout<<"Array : ";
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
            break;
        }  
}     
  return ;  
}
int main(){
    vector<int> nums ={-2, 1, -3, 4, -1, 2, 1, -5, 4};
    kadaneVisualizer(nums);
    return 0;
}