#include <iostream>
using namespace std;

struct array{
    int A[10];
    int size;
    int length;
};

void Display(struct array *arr){
    int i;
    for(i=0;i<arr->length;i++){
        cout<<arr->A[i]<<" ";
    }
    cout<<endl;
}

// If elements is starting from 1 in a sorted way
int FindElement(struct array *arr){
    int sum,n,S,x;
    sum = 0;
    for(int i = 0;i < arr->length;i++){
        sum = sum + arr->A[i];
    }
    n = arr->A[arr->length - 1];
    S = n*(n + 1) / 2;
    x = S - sum;
    return x;
}

//When elements are not starting from 1
int FindElement2(struct array *arr){
    int i,d;
    for(i=0;i<arr->length;i++){
        if(arr->A[i] - i != arr->A[0]){
            d = i + arr->A[0]; 
            return d;
        }
    }
}

//to find multiple missing elements 
void FindElements3(struct array *arr){
    int i,diff;
    i = 0;
    diff = arr->A[0] - i;
    for(;i<arr->length;i++){
        if(arr->A[i] - i != diff){
            while(diff< arr->A[i] - i){
                cout<<i + diff<<" ";
                diff++;
            }
        }
    }
}

int main(){
    struct array arr = {{1,2,3,4,6,7,8}, 10, 7};
    struct array arr1 = {{6,7,8,9,11,12,13}, 10, 7};
    struct array arr2 = {{3,4,5,7,9,10,12,14},10,8};

    // Display(&arr);

    // cout<<"Element which is missing is "<<FindElement(&arr)<<endl;
    // cout<<"Element which is missing is "<<FindElement2(&arr1)<<endl;
    FindElements3(&arr2);

    return 0;
}