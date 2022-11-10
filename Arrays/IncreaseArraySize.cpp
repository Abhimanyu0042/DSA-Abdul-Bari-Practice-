#include <iostream>
using namespace std;

int main(){
    int *P,*Q;

    Q = new int[10];
    P = new int[5];
    P[0]=3;
    P[1]=5;
    P[2]=7;
    P[3]=9;
    P[4]=11;

    for(int i = 0;i<5;i++){
        cout<<P[i]<<" ";
    }
    //Now we will try to increase the size of the array
    for(int i = 0;i<5;i++){
        Q[i]=P[i];
    }
    delete []P; 
    P = Q;
    Q = NULL;

    cout<<endl;

    for(int i = 0;i<5;i++){
        cout<<P[i]<<" ";
    }

    return 0;

}
