#include<iostream>
using namespace std;

int fun(int n){
    static int s=0;
    if(n>0){
        s++;
        return fun(n-1)+s;
    }
    return 0;
}

int main (){
    static int b=5;
    int a=5;
    cout<<fun(a)<<endl;

}



// in a function with non static variable.A new variable 'n' is created in the stack each time we call the function
// #include<iostream>
// using namespace std;

// int fun(int n){
//     if(n>0){
//         return fun(n-1)+n;
//     }
//     return 0;
// }

// int main (){
//     int a=5;
//     cout<<fun(a)<<endl;

// }


// <output>
// 15




// in a function which has static variable the variable is created only once
// <input>
// #include<iostream>
// using namespace std;

// int fun(int n){
//     static int s=0;
//     if(n>0){
//         s++;
//         return fun(n-1)+s;
//     }
//     return 0;
// }

// int main (){
//     int a=5;
//     cout<<fun(a)<<endl;

// }

// <output>
// 35