#include<iostream>
using namespace std;

int sum(int n){
    if(n>0)
        return sum(n-1)+n;
    return 0;
}

int main(){
    int s=10;
    cout<<sum(s);
}