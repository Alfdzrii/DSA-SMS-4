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

    int d;
    cout << "input the size of array: ";
    cin >> d;
    dataMove2 A[d];
    const int arraySize = d;

    for (int i = 0; i < arraySize; i++){
        cout << "number of "<< i +1 << ": ";
        cin >> A[i].data;
    }
    
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
