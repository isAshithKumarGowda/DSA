#include<iostream>
using namespace std;

int main(){
    int arr[5];
    arr[0]=1;
    arr[1]=2;
    for(int x:arr){
        cout<<x<<endl;
    }
}

/*          OUTPUT             
1
2
645690868
-2
6422280

it has give garbage values because we have assined the valuse after declaring the array */