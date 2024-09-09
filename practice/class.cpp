#include<iostream>

using namespace std;
template<class T>
class Arithemitic{
    T a;
    T b;
    public:
        Arithemitic(T a,T b);
        T add();
        T sub();

};

template<class T>
Arithemitic<T>::Arithemitic(T a,T b){
    this->a=a;
    this->b=b;
}

template<class T>
T Arithemitic<T>:: add(){
    return this->a+=b;
}

template<class T>
T Arithemitic<T>::sub(){
    return this->a-=b;
}

int main(){
    Arithemitic <int>a(10,20);
    cout<<a.add()<<endl;
    cout<<a.sub()<<endl;
    return 0;
}