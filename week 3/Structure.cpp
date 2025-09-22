#include <iostream>
using namespace std;

// struct = user defined data type
struct Data {
    int data;
    int nextIndex;
};

struct Student{
    string name;
    string id;
    string major;
    int batch;
    float gpa;
};

int main(){
    cout << "-----------------data structure-----------------" << endl;
    Data A[10];
    A[0].data = 10;
    A[0].nextIndex = 1;
    
    cout << A[0].data << endl;
    cout << A[0].nextIndex << endl;

    cout << "----------------------------------" << endl;
    cout << "----------------------------------" << endl;
    Student S[34];
    S[15].name = "John";

    cout << S[15].name << endl;
    cout << "----------------------------------" << endl;
    cout << "----------------------------------" << endl;

    return 0;
};
