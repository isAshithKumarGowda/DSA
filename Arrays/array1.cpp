#include<iostream>
using namespace std;

class Array{
    private:
        int *Arr;
        int size;
        int length;
    public:
        Array ();
        void setSize();
        void setLength();
        void setArr();
        int getSize();
        int getLength();
        int* getArr();
        void display();
        void insert(int &index,int value);
        void insertInSorted(int value);
        int get(int a);
        void add(int );
        void set(int index,int value);
        auto find(Array *A,int value);
        int Max();
        int Min();
        int sum();
        float avg();
        void Delete(int);
        void reverse();
        void auxReverse();
        void leftShift();
        void leftRotate();
        void rightShift();
        void rightRotate();
        int linearSearch(int key);
        int binarySearch(int key);
        int rBinarySearch(int key);
        void swap(int *from,int *to);
        auto isSorted();
        void negtOnLeft();
        int *Merge(Array *,Array *);
        int *concatinate(Array*,Array*);
        int compare(Array*,Array*);
        void copy(Array*,Array*);
        int Union(Array*,Array*);
        ~Array();
};

Array::Array(){
    cout<<"Enter the size of the array :"<<endl;
    setSize();
    cout<<"Enter the length of the array :"<<endl;
    setLength();
}


void Array::setSize(){
    cin>>size;
    Arr=new int [size];
}

void Array::setLength(){
    cin>>length;
    setArr();
}

void Array::setArr(){
    cout<<"Enter the (sorted) values :";
    for(int i=0;i<length;i++)
        cin>>Arr[i];
}

int Array::getSize(){
    return size;
}

int Array::getLength(){
    return length;
}

int* Array::getArr(){
    return Arr;
}

int Array::get(int a){
    if(a>=0&&a<length)
        return Arr[a];
     return -1;
}

void Array::set(int index,int value){
    if(index>0&&index<length)
        Arr[index]=value;
}

auto Array::find(Array *A,int value){
    for(int i=0;i<A->length;i++){
        if(value==A->Arr[i])
            return true;
    }
    return false;
}

int Array::Max(){
    int max=Arr[0];
    for(int i=0;i<length;i++){
        if(max<Arr[i])
            max=Arr[i];
    }
    return max;
}

int Array::Min(){
    int min=Arr[0];
    for(int i=0;i<length;i++){
        if(min>Arr[i])
            min=Arr[i];
    }
    return min;
}

int Array::sum(){
    int sum=0;
    for(int i=0;i<length;i++)
        sum+=Arr[i];
    return sum;
}

float Array::avg(){
    return (float)(sum()/length);
}

void Array::display(){
    cout<<"The size of the array is :"<<size<<endl;
    cout<<"The length of the array is :"<<length<<endl;
    cout<<"The values stored in the array are:"<<endl;
    cout<<"Index:Value"<<endl;
    for(int i=0;i<length;i++)
        cout<<i<<"    :"<<Arr[i]<<endl;
}
 
void Array::add(int value){
    char choice;
    if(length<size){
        Arr[length]=value;
        length++;
    }
    else{
        cout<<"The array is full ,if you procede it will change the size of the array"<<endl;
        cout<<"If you want to procede enter 'Y' else 'N' :";
        cin>>choice;
        if(choice=='Y'||choice=='y'){
            int *B;
            B=new int [++size];
            for(int i=0;i<length;i++)
                B[i]=Arr[i];
            delete []Arr;
            Arr=B;
            B=nullptr;
            Arr[length]=value;
            length++;
            display();
        }
        else{
            cout<<"Add Function ENDED!!!";
            return;
        }
    }
}

void Array::insert(int & index,int value){
    char choice;
    if(index>=0&&index<size){
        if(length<size){
            for(int i=length;i>index;i--)
                Arr[i]=Arr[i-1];
            Arr[index]=value;
            length++;
        }
        else{
            cout<<"The array is full ,if you procede it will change the size of the array"<<endl;
            cout<<"If you want to procede enter 'Y' else 'N' :";
            cin>>choice;
            if(choice=='Y'||choice=='y'){
                int *B = new int[++size];
                for (int i = 0; i < index; i++)
                    B[i] = Arr[i];
                B[index] = value;
                for (int i = index + 1; i <= length; i++)
                    B[i] = Arr[i - 1];
                delete[] Arr;
                Arr = B;
                B = nullptr;
                length++;
                display();
            }
            else{
                cout<<"Insert Function ENDED!!!";
                return;
            }
        }
    }
} 

void Array::insertInSorted(int value){
    int i=length-1;
    if(length<size){
        while(i>0&&Arr[i]>value){
            Arr[i+1]=Arr[i];
            i--;
        }
        Arr[i+1]=value;
        ++length;
    }
}

void Array::Delete(int index){
    if(index>=0&&index<length){
        for(int i=index;i<length;i++)
            Arr[i]=Arr[i+1];
        Arr[length-1]=0;
        --length;
    }
}

void Array::reverse(){
    int temp;
    for(int i=0,j=length-1;i<j;i++,j--){
        temp=Arr[i];
        Arr[i]=Arr[j];
        Arr[j]=temp;
    }
}

void Array::auxReverse(){
    int *B=new int [length];
    for(int i=0,j=length-1;j>=0;i++,j--)
        B[i]=Arr[j];
    for(int i=0;i<length;i++)
        Arr[i]=B[i];
}

void Array::leftShift(){
    static int l=length;
    for(int i=0;i<l;i++){
        if(i<l-1)
            Arr[i]=Arr[i+1];
        else
            Arr[i]=0;
    }
    l--;
}

void Array::leftRotate(){
    int temp=Arr[0];
    for(int i=0;i<length-1;i++)
        Arr[i]=Arr[i+1];
    Arr[length-1]=temp;
}

void Array::rightShift(){
    for(int i=length-1;i>0;i--)
        Arr[i]=Arr[i-1];
    Arr[0]=0;
}

void Array::rightRotate(){
    int temp=Arr[length-1];
    for(int i=length-1;i>0;i--)
        Arr[i]=Arr[i-1];
    Arr[0]=temp;
}

int Array::linearSearch(int key){
    for(int i=0;i<length;i++){
        if(key==Arr[i]){
            if(i>0){
                swap(&Arr[i],&Arr[i-1]);
                return i;
            }
        }
    }
    cout<<"Key was not found"<<endl;
    return -1;
}

int Array::binarySearch(int key){
    static int l=0;
    static int h=length-1;
    int mid;
    while(l<=h){
        mid=(l+h)/2;
        if(key==Arr[mid])
            return mid;
        else if(key<Arr[mid])
            h=key-1;
        else 
            l=key+1;
    }
    cout<<"The number was not found"<<endl;
    return -1;
}

int Array::rBinarySearch(int key){
    static int l=0;
    static int h=length-1;
    if(l<=h){
        int mid =(l+h)/2;
        if(key==Arr[mid])
            return mid;
        else if(key<Arr[mid]){
            h=mid-1;
            return rBinarySearch(key);
        }
        else{
            l=mid+1;
            return rBinarySearch(key);
        }
    }
    return -1;
}

void Array::swap(int *from , int *to){
    int temp;
    temp=*from;
    *from=*to;
    *to=temp;
    display();
}

auto Array::isSorted(){
    for(int i=0;i<length-1;i++){
        if(Arr[i]>Arr[i+1])
            return false;
    }
    return true;
}

void Array::negtOnLeft(){
    int i=0;
    int j=length-1;
    while(i<j){
        while(Arr[i]<0){++i;};
        while(Arr[j]>=0){--j;};
        swap(&Arr[i],&Arr[j]);
            
    }
}

int *Array::Merge(Array* A,Array *B){
    int m=A->length;
    int n=B->length;
    int i=0,j=0,k=0;
    int *C=new int [m+n];
    while(i<m&&j<n){
        if(A->Arr[i]<B->Arr[j])
            C[k++]=A->Arr[i++];
        C[k++]=B->Arr[j++];
    }
        for(;j<n;j++)
            C[k++]=B->Arr[j];
        for(;i<m;i++)
            C[k++]=A->Arr[i];
    return C;
}

int *Array::concatinate(Array *A,Array*B){
    int m=A->length;
    int n=B->length;
    int *C=new int [m+n];
    for(int i=0;i<m;i++)
        C[i]=A->Arr[i];
    for(int i=0;i<n;i++)
        C[i]=B->Arr[i];
    return C;
}

void Array::copy(Array *A,Array *B){
    int m=A->length;
    int n=B->length;
    if(m>=n){
        for(int i=0;i<n;i++){
            A->Arr[i]=B->Arr[i];
        }
    }
    else
        cout<<"Copy Unsuccessfull";
}

int Array::compare(Array *A,Array *B){
    if(A->length!=B->length)    
        cout<<"The arrays are not equal "<<endl;
    else{
        for(int i=0;i<A->length;i++){
            if(A->Arr[i]!=B->Arr[i]){
                cout<<"They are not equal"<<endl;
                return -1;
            }
        }
        return 1;
    }

}
int Array::Union(Array*A,Array*B){
    int s=A->length+B->length;
    int *C=new int [s];
    int i;
    for(i=0;i<A->length;i++)
        C[i]=A->Arr[i]; 
    for(int k=0;k<B->length;k++){
        if(!find(A,B->Arr[k]))
            C[i++]=B->Arr[k];
    }
}

Array::~Array(){
    delete[] Arr;
    Arr=nullptr;
}