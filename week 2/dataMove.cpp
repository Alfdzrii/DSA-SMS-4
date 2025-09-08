#include <iostream>
using namespace std;

void MovingDown (int x[], int index, int lastindex){
    int temp = lastindex;
        while (temp == index){
            x[temp] = x[temp-1];
            temp--;
        }
}

void MovingUp (int z [], int total){
    for (int i=0;i<total;i++){
        if (i == total-1)
            cout << z[i] << endl;
        else
            cout << z[i] << ", ";
        // (i ==(total-1))? cout << z[i] :cout << z[i]<< ", ";
        // cout << endl;
    }
}

int main(){
}