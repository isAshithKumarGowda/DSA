#include<iostream>

using namespace std;
struct Rectangle{
    long length;
    int breadth;
    char x;
};
int main(){
    int s=sizeof(Rectangle);
    cout<<s<<endl;
}