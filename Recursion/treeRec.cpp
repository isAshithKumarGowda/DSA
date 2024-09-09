#include<iostream>
using namespace std;


void funA(int n){
    if(n>0){
        cout<<n;
        funA(n-1);
        funA(n-1);
    }
}



int main(){
funA(3);
} 