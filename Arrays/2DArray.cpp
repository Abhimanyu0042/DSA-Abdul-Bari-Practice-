#include <iostream>
using namespace std;

int main(){

    //this array will be stored in stack memory
    int A[3][4] = {{1,2,3,4},{2,4,6,8},{1,3,5,7}};

    for(int i = 0;i<3;i++){
        for(int j = 0;j<4;j++){
            cout<<A[i][j]<<" ";
        }
        cout<<endl;
    }

    int *B[3]; //this part will be in stack memory
    // this part will be in heap memory
    B[0] = new int[4];
    B[1] = new int[4];
    B[2] = new int[4];

    //As no value in initialized in this 2D array thus it will print garbage value
    for(int i = 0;i<3;i++){
        for(int j = 0;j<4;j++){
            cout<<B[i][j]<<" ";
        }
        cout<<endl;
    }

    //Now to make each and evry part in heap memory we take pointer var also in heap memory as in line31
    int **C[3];
    C[0] = new int*[4];
    C[1] = new int*[4];
    C[2] = new int*[4];

    cout<<"Output of 2D Array in which var is also in heap"<<endl;

    for(int i = 0; i<3; i++){
        for(int j = 0; j<4; j++){
            cout<<C[i][j]<<" ";
        }
        cout<<endl;
    }

}

