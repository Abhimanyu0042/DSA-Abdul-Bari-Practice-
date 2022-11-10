#include <iostream>
using namespace std;

int main(){
    //it stores array in stack.
    int A[5] = {2,4,6,8,10};

    //its stores array in heap thats why pointer is used.
    int *P;
    P = new int[5];
    P[0]=3;
    P[1]=5;
    P[2]=7;
    P[3]=9;
    P[4]=11;

    for(int i = 0;i<5;i++){
        cout<<A[i]<<" ";
    }
    
    cout<<endl;

    for(int i = 0;i<5;i++){
        cout<<P[i]<<" ";
    }

    //int variable takes 4 bits, We can check by printing address
    for(int i = 0;i<5;i++){
        cout<<&A[i]<<" ";
    }
    return 0;

}
