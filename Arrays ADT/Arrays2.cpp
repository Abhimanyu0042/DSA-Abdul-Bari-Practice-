#include<iostream>
using namespace std;

struct array{
    int *A;
    int size;
    int length;
};

void Display(struct array *arr){
    cout<<"Elements are -"<<endl;
    for(int i = 0;i<arr->length;i++){
        cout<<arr->A[i]<<" ";
    }
    cout<<endl;
}

int Get(struct array *arr, int index){
    int x = 0;
    if(index>=0 && index<arr->length){
    x = arr->A[index];
    cout<<"Element at "<<index<<" is "<<x<<endl;
    }
    else{
        cout<<"Invalid index"<<endl;
    }
}

int set(struct array *arr, int ele, int index){
    if(index >= 0 && index < arr->length){
        arr->A[index] = ele;
    }
}

int max(struct array *arr){
    int max = arr->A[0];
    for(int i = 1;i<arr->length;i++){
        if(max < arr->A[i]){
            max = arr->A[i];
        }
    }
    cout<<"maximum element is - "<<max<<endl;
}

int min(struct array *arr){
    int min = arr->A[0];
    for(int i = 1;i<arr->length;i++){
        if(min > arr->A[i]){
            min = arr->A[i];
        }
    }
    cout<<"minimum element is - "<<min<<endl;
}

int sum(struct array *arr){
    int total = 0;
    for(int i = 0; i<arr->length; i++){
        total = total + arr->A[i];
    }
    cout<<"Sum of elements is "<<total<<endl;
}

int average(struct array *arr){
    int total = 0;
    float average;
    for(int i = 0; i<arr->length; i++){
        total = total + arr->A[i];
    }
    average = total/arr->length;
    cout<<"Average of elements is "<<average<<endl;
}

int main(){
    struct array arr;
    int n,i;

    cout<<"Enter the size of the array"<<endl;
    cin>>arr.size;

    arr.A = new int[arr.size]; 
    arr.length = 0;

    cout<<"Enter the number of elements"<<endl;
    cin>>n;

    cout<<"Enter the elements in the array"<<endl;
    for(int i=0;i<n;i++){
        arr.length = n;
        cin>>arr.A[i];
    }

    Display(&arr);

    Get(&arr,2);

    set(&arr,1,3);

    Display(&arr);

    max(&arr);

    min(&arr);

    sum(&arr);

    average(&arr);


}