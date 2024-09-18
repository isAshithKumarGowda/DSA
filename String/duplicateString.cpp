#include<iostream>
#include<string.h>

using namespace std;

int main(){
    string str;
    int H=0,S;
    cout<<"Enter a string : ";
    getline(cin,str);
    for(int i=0;i<str.length();i++){
        S=1;
        S=S<<(str[i]-97);
        if((S&H)>0){
            cout<<str[i]<<" is Duplicate ";
        }else{
            H=(S|H);
        }
    }
}