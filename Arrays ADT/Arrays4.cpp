#include <iostream>
using namespace std;

struct array{
    int *A;
    int size;
    int length;
};

void Display(struct array *arr){
    int i = 0;
    for(i = 0;i<arr->length;i++){
        cout<<arr->A[i]<<" ";
    }
    cout<<endl;
}

int insertSorted(struct array *arr, int x){
    int i = arr->length-1;
    if(arr->length == arr->size){
        return false;   
    }
    while(i>=0 && arr->A[i]>x){
        arr->A[i+1] = arr->A[i];
        i = i - 1;
    }
    arr->A[i+1] = x;
    arr->length++;
}

int isSorted(struct array *arr){
    for(int i = 0; i<arr->length;i++){
        if(arr->A[i] > arr->A[i+1]){
            return false;
        }
    }
    return true;
}

//to arrange elements in -ve left side and +ve right side
void rearrange(struct array *arr){
    int i,j;
    i = 0;
    j = arr->length -1;
    while(i<j){
    while(arr->A[i]<0){
        i++;
    }
    while(arr->A[j]>0){
        j--;
    }
    if(i<j){
        int temp;
        temp = arr->A[i];
        arr->A[i] = arr->A[j];
        arr->A[j] = temp;
    }
    }
}

int main(){
    struct array arr;
    int n,i;

    cin>>arr.size;

    arr.A = new int[arr.size];
    arr.length = 0;

    cin>>n;

    for(int i = 0;i<n;i++){
        cin>>arr.A[i];
        arr.length = n;
    }

    // Display(&arr);

    // insertSorted(&arr,15);

    Display(&arr);

    //cout<<isSorted(&arr)<<endl;

    rearrange(&arr);

    Display(&arr);
 }