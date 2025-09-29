#include <iostream>
#define size 20
using namespace std;
struct Stack{
	int ToS = -1;
	int Data[size];
};
int menu()
{
  int ans;
	cout << " --Menu Stack Using Array--\n";
	cout << "1. Insert\n";
	cout << "2. Delete\n";
	cout << "3. Exit\n";
	cout << "Select your choice: ";
	cin >> ans;
	return ans;
}
void Insert(Stack *S,int x)
{
	if(S->ToS == (size-1))
	    cout << "Stack is full!!\n";
	else
	    S->Data[++(S->ToS)] = x;
}
void Delete(Stack *S,int *dat)
{
	if(S->ToS >= 0)
	    *dat = S->Data[(S->ToS)--];
	else
	    cout << "Nothing to be deleted!!\n";
}
void PrintData(Stack *S)
{
  int index = S->ToS;
  while(index >=0){
      cout << S->Data[index--] << " ";
  }
  cout << endl;
}
int main()
{
Stack *St = new(Stack);
int data,choice;
char ans[2];
	do{
		choice = menu();
		switch(choice){
			case 1:
				cout << "Put the data to be inserted: ";
				cin >> data;
				Insert(St,data);
				break;
			case 2:
				Delete(St,&data);
				break;
			case 3:
				ans[0] = 'N';
				break;
		}
		if(choice != 3){
			cout << "The sequence is: \n";
			PrintData(St);
		}
		cout << "Press y to continue: ";
		cin >> ans;
	}while(ans[0] == 'y' || ans[0] == 'Y');
	return 0;
}
