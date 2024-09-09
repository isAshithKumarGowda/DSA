#include<iostream>

using namespace std;

struct Rectangle{
    int length ;
    int breadth;
};

int main(){
    // Rectangl r={1,3};
    // cout<<r.length<<endl;
    // cout<<r.breadth<<endl;
    // //when using a normal variable use . operator 
    // //when using a pointer variable use -> operator
    // Rectangl *p=&r;
    // cout<<p->length<<endl;
    // cout<<p->breadth<<endl;

    Rectangle *a;
    a=new Rectangle;
    a->length=2;
    a->breadth=3;
    cout<<a->length<<endl;
    cout<<a->breadth<<endl;
}