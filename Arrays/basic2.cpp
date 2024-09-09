#include<iostream>
using namespace std;

int main(){
    int A[5];
    int *p;
    
    for(int i=0;i<5;i++)
        A[i]=i;
    
    p=new int [5];
    for(int i=0;i<5;i++)
        p[i]=i;
    for(int i=0;i<5;i++)
        cout<<A[i]<<endl;
    for(int i=0;i<5;i++)
        cout<<p[i]<<endl;
    delete []p;
    p=nullptr;
}
    