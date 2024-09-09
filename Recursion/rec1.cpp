#include<iostream>
using namespace std;
int fun(int x){
    if(x>0){
        cout<<x<<endl;
        fun(x-1);
    }
}
int main(){
    int x=5;
    fun(x);
}
 
// <input> this is called a head recursion
// #include<iostream>
// using namespace std;
// int fun(int x){
//     if(x>0){
        
//         fun(x-1);
//         cout<<x<<endl;
//     }
// }
// int main(){
//     int x=5;
//     fun(x);
// }

// <output>
// 1
// 2
// 3
// 4
// 5

 

// <input> this is called a tail recursion 
// #include<iostream>
// using namespace std;
// int fun(int x){
//     if(x>0){
//         cout<<x<<endl;
//         fun(x-1);
//     }
// }
// int main(){
//     int x=5;
//     fun(x);
// }


// <output>
// 5
// 4
// 3
// 2
// 1