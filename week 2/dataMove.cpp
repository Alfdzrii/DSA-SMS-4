#include <iostream>
using namespace std;

void MovingRight(int arr[], int currentSize, int insertIndex){
    for (int i = currentSize; i > insertIndex; i--){
        arr[i] = arr [i-1];
    }
}

void insertArray (int arr[], int size){
    for (int i = 0; i < size; i++){
        cout << arr[i];
        if (i < size - 1){
            cout << ", ";
        }
    }
    cout << endl;
}

int main(){
    const int CAPACITY = 10;
    int number[CAPACITY];
    int currentSize = 0;

    cout <<"input 10 numbers: "<< endl;
    cout <<"input how many numbers that you want to insert: "<< "maximal is "<< CAPACITY<< endl;
    cin >> currentSize;

    while (currentSize > CAPACITY || currentSize < 0){
        cout << "input again: "<< endl;
        cin >> currentSize;
    }

        cout << "please intput the numbers: " << endl;
    for (int i = 0 ; i < currentSize; i++){
        cout << "number of "<< i +1 << ": ";
        cin >> number[i];
    }

    cout << "\n array before moving: " << endl;
    instertArray (number, currentSize);

    if (currentSize < CAPACITY){
        cout << "\n new storage of array: " << endl;
        int valueInsert, insertIndex;

        cout << "input the number that you want to insert: ";
        cin >> valueInsert;

        cout << "input the index that you want to insert: ";
        cin >> insertIndex;
    }

}