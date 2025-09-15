#include <iostream>
using namespace std;

struct dataMove2
{
    int data;
    int nextIndex;
};

void printArray (const dataMove2 arr[], int size){
    for (int i = 0; i < size; i++){
        cout << arr[i].data <<", ";
    }
}

int main(){

    dataMove2 A[10];
    const int arraySize = 9;

    A[0].data = 10;
    A[1].data = 20;
    A[2].data = 16;
    A[3].data = 14;
    A[4].data = 12;
    A[5].data = 432;
    A[6].data = 111;
    A[7].data = 43;
    A[8].data = 1;
    A[9].data = 13;
    
    printArray(A, arraySize);
    cout << endl;

    for (int i = 0; i < arraySize - 1; i++){
        for (int j = 0; j < arraySize - i - 1; j++){
            if (A[j].data > A[j+1].data){
                dataMove2 temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
            }
        }
    }
    cout<< "after sorting";
    printArray(A, arraySize);
    return 0;
}
