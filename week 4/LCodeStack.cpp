#include <iostream>
using namespace std;

struct LCodeStack
{
    int data;
    LCodeStack *next;
};

int menu()
{
    int ans;
    cout<<"input the number that you want to insert: \n";
    cout<<"1. insert\n";
    cout<<"2. delete\n";
    cout<<"3. exit\n";
    cin >> ans;
    return ans;
}

LCodeStack *insert (LCodeStack *frnt, int value){
    LCodeStack *temp = new (LCodeStack);
    temp->data = value;
    temp->next = frnt;
    frnt = temp;
    return frnt;

};

LCodeStack *Delete (LCodeStack *frnt){
    LCodeStack *temp = frnt;
    frnt = frnt->next;
    delete(temp);
    return frnt;
};

void printData(LCodeStack *frnt){
    LCodeStack *cur = frnt;
    while (cur) {
        cout << cur ->data << " ";
        cur = cur->next;
    }
    cout << endl;
}

int main(){
    LCodeStack *front =0;
    int data,choice;

    char ans[2]={1,1};
    do {
        choice = menu();
        switch (choice)
        {
        case 1:
            cout << "insrt data \n";
            cin >> data ;
            front = insert (front, data);
            printData(front);
            break;
        case 2:
            front = Delete(front);
            printData(front);
            break;
        case 3:
            ans[0]=0;
            break;

        }
    }
    while (ans[0]);
    
}
