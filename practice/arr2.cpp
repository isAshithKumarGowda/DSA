#include<iostream>
using namespace std;

int main(){
    int arr[5]={1,3};
    for(int x:arr){
        cout<<x<<endl;
    }
}


/*          OUTPUT             
1
3
0
0
0

it has give 0 as the value to all the index which does not store a 
value because i have partially initialized it during the declaration*/