#include<iostream>
#include<utility>
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
        int* Union(Array*,Array*);
        int* sortedUnion(Array*,Array*);
        int* Intersection(Array*,Array*);
        int* Differece(Array*,Array*);
        void missingEleSA();
        void missingEleUA();
        void duplicate();
        void sumK(int key);
        void sumKSA(int key);
        std::pair<int,int> maxMin();
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
        while(i>=0&&Arr[i]>value){
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
            h=mid-1;
        else 
            l=mid+1;
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

    int* result = new int[m+n];
    std::copy(C, C + (m+n), result);
    delete[] C;

    return result;
    
}

int *Array::concatinate(Array *A,Array*B){
    int m=A->length;
    int n=B->length;
    int *C=new int [m+n];
    for(int i=0;i<m;i++)
        C[i]=A->Arr[i];
    for(int i=0;i<n;i++)
        C[i]=B->Arr[i];

    int* result = new int[m+n];
    std::copy(C, C + (m+n), result);
    delete[] C;

    return result;}

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
int* Array::Union(Array*A,Array*B){
    int s=A->length+B->length;
    int *C=new int [s];
    int i;
    for(i=0;i<A->length;i++)
        C[i]=A->Arr[i]; 
    for(int k=0;k<B->length;k++){
        if(!find(A,B->Arr[k]))
            C[i++]=B->Arr[k];
    }

    int* result = new int[s];
    std::copy(C, C + s, result);
    delete[] C;

    return result;
}

int* Array::sortedUnion(Array *A,Array *B){
    int *C=new int [A->length+B->length];
    int i=0,j=0,k=0;
    do{
        if(A->Arr[i]<B->Arr[j])
            C[k++]=A->Arr[i++];
        else if(B->Arr[j]<A->Arr[i])
            C[k++]=B->Arr[j++];
    }while(i<A->length&&j<B->length);

    while(i<A->length)
        C[k++]=A->Arr[i++];
    while(j<B->length)
        C[k++]=B->Arr[j++];

    int* result = new int[k];
    std::copy(C, C + k, result);
    delete[] C;

    return result;
}

int* Array::Intersection(Array* A,Array* B ){
    int *C=new int [A->length+B->length];
    int k=0;
    for(int i=0;i<A->length;i++){
        if(find(A,B->Arr[i]))
            C[k++]=B->Arr[i];
    }

    int* result = new int[k];
    std::copy(C, C + k, result);
    delete[] C;

    return result;
}

int * Array::Differece(Array*A,Array*B){
    int *C=new int [A->length+B->length];
    int k=0;
    for(int i=0;i<A->length;i++){
        if(!find(B,A->Arr[i]))
            C[k++]=A->Arr[i];
    }

    int* result = new int[k];
    std::copy(C, C + k, result);
    delete[] C;

    return result;
}

void Array::missingEleSA(){
    int diff=Arr[0];
    for(int i=0;i<length;i++){
        if(Arr[i]!=i+diff){
            while(Arr[i]<i+diff){
                cout<<i+diff<<endl;
                diff++;
            }
        }
    }
}

void Array::missingEleUA(){
    int m=Max();
    int H[m+1]={0};
    int v;
    for(int i=0;i<length;i++){
        v=Arr[i];
        H[v]++;
    }
    for(int i=0;i<=m;i++){
        if(H[i]==0){
            cout<<i<<endl;
        }
    }
}

void Array::duplicate(){
    int m=Max();
    int H[m+1]={0};
    int v;
    for(int i=0;i<length;i++){
        v=Arr[i];
        H[v]++;
    }
    for(int i=0;i<m;i++){
        if(H[i]>1){
            cout<<i<<" has multiple elements."<<endl;
            cout<<i<<" has been repeated "<<H[i]<<" times"<<endl;
        }
    }
}

// void Array ::duplicate(){
//     int lastDuplicate;
//     for(int i=0;i<length;i++){
//         if(Arr[i]==Arr[i+1]&&Arr[i]!=lastDuplicate){
//             cout<<Arr[i]<<endl;
//             lastDuplicate++;
//         }
//     }
// }

// void Array::duplicate(){
//     int j;
//     for(int i=0;i<length-1;i++){
//         if(Arr[i]==Arr[i+1]){
//             j=i+1;
//             while(j<length&&Arr[j]==Arr[i])j++;
//             cout<<Arr[i]<<" is appering "<<j-i<<" times"<<endl;
//             i=j-1;
//     }
// }

// void Array::sumK(int key){                      the function has time complexity of O(n^2);
//     for(int i=0;i<length-1;i++){
//         for(int j=i+1;j<length;j++){
//             if(Arr[i]+Arr[j]==key){
//                 cout<<Arr[i]<<'+'<<Arr[j]<<'='<<key<<endl;
//             }
//         }
//     }
// }

void Array::sumK(int key){
    int H[Max()]={0};
    for(int i=0;i<length;i++){
        int v=Arr[i];
        int value=key-v;
        if(H[value]==1&&value<=Max()&&value>=0){
            cout<<v<<'+'<<value<<'='<<key<<endl;
        }
        H[v]=1;
    }
}

void Array::sumKSA(int key){
    for(int i=0,j=length-1;i!=j;){
        int sum=Arr[i]+Arr[j];
        if(sum==key){
            cout<<Arr[i]<<'+'<<Arr[j]<<'='<<key;
            i++;
            j--;
        }
        else if(sum>key)
            j--;
        else 
            i++;
    }
}

std::pair<int,int> Array::maxMin(){
    int max=Arr[0];
    int min=Arr[0];
    for(int i=1;i<length;i++){
        if(max<Arr[i])
            max=Arr[i];
        if(min>Arr[i])
            min=Arr[i];
    }
    return std::make_pair(max,min);
}

Array::~Array(){
    delete[] Arr;
    Arr=nullptr;
}