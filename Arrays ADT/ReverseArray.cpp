#include <iostream>
using namespace std;

struct array{
    int *A;
    int size;
    int length;
};

void Display(struct array *arr){
    int i = 0;
    for(int i = 0;i<arr->length;i++){
        cout<<arr->A[i]<<" ";
    }
    cout<<endl;
}

int reverse(struct array *arr){
    int temp;
    for(int i = 0,j=arr->length - 1;i<j;i++,j--){
        temp = arr->A[i];
        arr->A[i] = arr->A[j];
        arr->A[j] = temp;
    }
}

int main(){
    struct array arr;
    int n,i;

    cout<<"Enter the size of the array - "<<endl;
    cin>>arr.size;

    arr.A = new int[arr.size];
    arr.length = 0;

    cout<<"Enter the number of Elements - "<<endl;
    cin>>n;

    cout<<"Enter the elements - "<<endl;
    for(int i = 0;i<n;i++){
        cin>>arr.A[i];
        arr.length = n;
    }

    Display(&arr);

    reverse(&arr);

    Display(&arr);
}