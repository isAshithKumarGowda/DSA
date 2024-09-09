#include<iostream>
using namespace std;

class Array{

};
int main(){
    Array A;
    char choise;
    int index,value;
    cout<<"Do you want to add a number to the array ?"<<endl;
    cout<<"If yes enter 'Y' else enter 'N' : ";
    cin>>choise;
    if(choise == 'Y'||choise=='y'){
        cout<<"enter the value to be added :";
        cin>>value;
        A.add(value);
    }
    cout<<"Do you want to insert an element at a specific index ?"<<endl;
    cout<<"If yes enter 'Y' else enter 'N' : ";
    cin>>choise;
    if(choise == 'Y'||choise =='y'){
        cout<<"enter the index and the value you want to store in it :";
        cin>>index>>value;
        A.insert(index,value);
    }
    A.display();
    cout<<"Do you want to Delete any element ??"<<endl;
    cout<<"Enter 'Y' if you want to delete else ENTER 'N' : ";
    cin>>choise;
    if(choise=='y'||choise=='Y'){
        cout<<"enter the index you want to delete"<<endl;
        cin>>index;
        A.Delete(index);
        A.display();
    }
    cout<<"Do you want to scearch any element ??"<<endl;
    cout<<"If yes ENTER 'Y' else ENTER 'N' :";
    cin>>choise;
    if(choise=='Y'||choise=='y'){
        cout<<"Do you want to do a linear Search or Binary Search : "<<endl;
        cout<<"1 Linear Search \n 2 Binary Search"<<endl;
        cin>>choise;
        cout<<"Enter the value to be searched : ";
        int key;
        cin>>key;
        if(choise=='1')
            A.linearSearch(key);
        else 
            A.binarySearch(key);
    }
}