#include <iostream>
using namespace std;

struct array{
    int A[10];
    int size;
    int length;
};

int minmax(struct array *arr){
    int min,max;
    min = arr->A[0];
    max = arr->A[0];
    for(int i = 1; i<arr->length;i++){
        if(arr->A[i] < min){
            min = arr->A[i]; 
        }
        else if(arr->A[i] > max){
            max = arr->A[i];
        }
    }
    cout<<min<<" "<<max <<endl;
}

int main(){
    struct array arr = {{7,3,5,1,9,2,5,2,8},10,9};
    minmax(&arr);
}