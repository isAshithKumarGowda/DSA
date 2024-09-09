#include<iostream>
using namespace std;

int fact(int n){
    if(n==0)
        return 1;
    return fact(n-1)*n;
}

int nCr(int n,int r){
    int t1,t2,t3;
    t1=fact(n);
    t2=fact(r);
    t3=fact(n-r);
    return t1/(t2*t3);
}

int main(){
    cout<<nCr(5,3);
    return 0;
}