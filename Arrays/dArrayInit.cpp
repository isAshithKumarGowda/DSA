#include<iostream>
using namespace std;

int main(){
    int *A,**B,*C[3];
    A=new int [3];//single dimentional array



    B=new int *[3];//two dimentional array 
    B[0]=new int [4];
    B[1]=new int [4];
    B[2]=new int [4];



    C[0]=new int [4];//two dimentional array
    C[1]=new int [4];
    C[2]=new int [4];

    return 0;
} 