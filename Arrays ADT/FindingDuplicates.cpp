#include <iostream>
using namespace std;

struct array{
    int A[10];
    int size;
    int length;
};

//these two function will work for sorted arrays only
void WhichDuplicate(struct array *arr){
    int LastDuplicate = 0;
    for(int i = 0; i<arr->length;i++){
        if(arr->A[i] == arr->A[i + 1] && arr->A[i] != LastDuplicate){
            cout<<"There are Duplicates of elements "<<arr->A[i]<<endl;
            LastDuplicate = arr->A[i];
            continue;
        }
    }
}

void SFindDuplicate(struct array *arr){
    int j;
    for(int i = 0; i<arr->length;i++){
        if(arr->A[i] == arr->A[i+1]){
            j = i + 1;
            while(arr->A[j] == arr->A[i]){
                j++;
                cout<<arr->A[i]<<" appeared for "<<j-i<<endl;
            }
            i = j - 1;
        }
    }
}

void UFindDuplicate(struct array *arr){
    int j;
    for(int i = 0; i<arr->length;i++){
        int count = 1;
        if(arr->A[i] != -1)
        for(j=i+1;j<arr->length;j++){
            if(arr->A[i] == arr->A[j]){
                count++;
                arr->A[j] = -1; 
            }
        }
        if(count > 1)
        cout<<arr->A[i]<<" appeared for "<<count<<" times in an unsorted array."<<endl;
    }
}

int main(){
    struct array arr = {{1,2,3,4,4,5,5,5,6,7},10,9};
    struct array arr1 = {{22,5,1,3,4,3,9,5,5},10,9};

    WhichDuplicate(&arr);
    // SFindDuplicate(&arr);
    UFindDuplicate(&arr1);
    return 0;
}