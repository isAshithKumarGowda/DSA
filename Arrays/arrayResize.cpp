#include<iostream>
using namespace std;

int main(){
    int *p;
    int *q;
    p=new int [5];
    cout<<&p[1]<<endl;
    q=new int [10];
    cout<<&q[1]<<endl;
    delete p;
    p=q;
    q=nullptr;
    cout<<&p[1]<<endl;
    delete p;
    p=nullptr;
    return 0;
}