#include <iostream>
using namespace std;
struct Lstack{
	int data;
	Lstack *next;
};
int menu()
{
  int ans;
	cout << " --Menu--\n";
	cout << "1. Insert\n";
	cout << "2. Delete\n";
	cout << "3. Exit\n";
	cout << "Select your choice: ";
	cin >> ans;
	return ans;
}
Lstack *Insert(Lstack *frnt,int x)
{
	Lstack *temp = new(Lstack);
	temp->data = x;
	temp->next = frnt;
	return temp;
}
Lstack *Delete(Lstack *frnt)
{
	if(frnt != 0){
	    Lstack *temp = frnt;
	    frnt = frnt->next;
	    delete(temp);
	}else cout << "No data to be deleted!!!\n";
	return frnt;
}
void PrintData(Lstack *frnt)
{
  Lstack *cur = frnt;
  while(cur){
      cout << cur->data << " ";
      cur = cur->next;
  }
  cout << endl;
}
int main()
{
Lstack *front = 0;
int data,choice;
char ans[2];
	do{
		choice = menu();
		switch(choice){
			case 1:
				cout << "Put the data to be inserted: ";
				cin >> data;
				front = Insert(front,data);
				break;
			case 2:
				front = Delete(front);
				break;
			case 3:
				ans[0] = 'N';
				break;
		}
		if(choice != 3){
			cout << "The sequence is: \n";
			PrintData(front);
		}
		cout << "Press y to continue: ";
		cin >> ans;
	}while(ans[0] == 'y' || ans[0] == 'Y');
	return 0;
}