#include <iostream>
using namespace std;

struct array
{
    int *A;
    int size;
    int length;
};

void Display(struct array arr){
    int i;
    cout<<"Elements are - ";
    for(int i = 0;i<arr.length;i++){
        cout<<arr.A[i]<<" ";
    }
}

int main(){
    struct array arr;
    int n,i;

    cout<<"Enter the size of the array - "<<endl;
    cin>>arr.size;
    
    arr.A = new int[arr.size];
    arr.length = 0;

    cout<<"Enter number of elements - "<<endl;
    cin>>n;
    
    cout<<"Enter the Elements - "<<endl;
    for(int i = 0;i<n;i++){
        cin>>arr.A[i];
        arr.length = n;
    }
    

    Display(arr);

    return 0;
}