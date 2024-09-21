#include<iostream>
#include<string.h>
using namespace std;

int main(){
    string str1,str2;
    int res1[26]={0};
    int res2[26]={0};
    int x;
    cout<<"Enter the two strings :"<<endl;
    getline(cin,str1);
    getline(cin,str2);
    if(str1.length()==str2.length()){
        for(int i=0;i<str1.length();i++){
            if(str1[i]>=97){
                x=str1[i]-97;
                res1[x]++;
            }
        }
        for(int i=0;i<str2.length();i++){
            if(str2[i]>=97){
                x=str2[i]-97;
                res2[x]++;
            }
        }
        for(int i=0;i<str2.length();i++){
            
            if(res1[i]!=res2[i]){
                cout<<"The given strings are not anagram "<<endl;
                exit(0);
            }
        }
        cout<<"The given strings are in anagram"<<endl;
    }
    else
        cout<<"The given strings are not a anagram "<<endl;

}