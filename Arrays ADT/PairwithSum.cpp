//to find the pair of element having given sum

#include <iostream>
using namespace std;

struct array{
    int A[10];
    int size;
    int length;
};

int PairEle(struct array *arr, int k){
    for(int i = 0;i<arr->length - 1;i++){
        for(int j = i+1;j<arr->length;j++){
            if(arr->A[i] + arr->A[j] == k){
                cout<<arr->A[i]<<" & "<<arr->A[j]<<" have a sum "<<k<<endl;
            }
        }
    }
}

int main(){
    struct array arr = {{7,3,5,1,9,2,5,2,8},10,9};
    struct array arr1 = {{1,2,3,5,6,8,11,12,13},10,9};

    PairEle(&arr1,10);

}