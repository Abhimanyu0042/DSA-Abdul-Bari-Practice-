#include <iostream>
using namespace std;

//Initializing inputs for arrays in a structure
struct array
{
    //First pointer is created
    int *A;
    int size;
    int length;
};

int swap(int *x, int *y){
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void Display(struct array arr){
    int i;
    cout<<"Elements are - ";
    for(int i = 0;i<arr.length;i++){
        cout<<arr.A[i]<<" ";
    }
    cout<<endl;
}

//This function is used to add the element at the end of the array.
int append(struct array *arr,int x){
    if(arr->length<arr->size){
    arr->A[arr->length] = x;
    arr->length++;
    }
}

//To insert element at any given index
int insert(struct array *arr,int index,int x){
    if(index>=0 && index <= arr->length){
    for(int i = arr->length;i>index;i--){
        arr->A[i] = arr->A[i-1];
    }
    arr->A[index] = x;
    arr->length++;
    }
}

int Delete(struct array *arr, int index){
    if(index>=0 && index <= arr->length){
        for(int i = index; i<arr->length - 1;i++){
            arr->A[i] = arr->A[i+1];
        }
        arr->length--;
    }
}

//Search is of two types : Linear Search and Binary Search
//Linear Search have two ways to reduce time complexity for next search
//transposition - element is swapped with its previous one.
//front element - element is swapped with first element. 
int Linearsearch(struct array *arr, int key){
    for(int i = 0;i<arr->length;i++){
        if(key == arr->A[i]){
            swap(arr->A[i],arr->A[i-1]);
            cout<<i;
        }
    }
    
}

//For Binary the array will be split into two

int main(){
    struct array arr;
    int n,i;
    
    //First we will take for how much size array should be initialized
    cout<<"Enter the size of the array - "<<endl;
    cin>>arr.size;
    
    //Here we are creating the array
    arr.A = new int[arr.size];
    arr.length = 0;

    //No. of elements we want to enter in the initialized array 
    cout<<"Enter number of elements - "<<endl;
    cin>>n;
    
    cout<<"Enter the Elements - "<<endl;
    for(int i = 0;i<n;i++){
        cin>>arr.A[i];
        arr.length = n;
    }
    

    Display(arr);

    append(&arr,15);

    Display(arr);

    insert(&arr, 4,222);

    Display(arr);

    Delete(&arr,4);

    Display(arr);

    Linearsearch(&arr,6);

    Display(arr);

    return 0;
}