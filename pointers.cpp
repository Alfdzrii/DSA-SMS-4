#include <iostream>
using namespace std;

int main(){
    int p[5], gtr=0, *ptr;
    long sum = 0;
    float avg;
    for (int i=1 ; i<=5 ; i++){
        cout << "Enter number " << i << " data: ";
        cin >> *ptr;
        sum += *ptr;
    }

    cout<< "Sum = " << sum << endl;
    avg = sum/5;
    for (int i = 1 ; i <5; i++){
        if (*ptr >= avg)
            gtr++;
            ptr++;
        }
        cout << "avarage = " << avg << endl;
        cout <<"data that are greater than equal to avarage = " << gtr << endl;
        
        
    // int a = 5, *b;
    // b = &a;
    // *b -= 10;
    // cout << "Value of a = " << a << endl;

return 0;
}