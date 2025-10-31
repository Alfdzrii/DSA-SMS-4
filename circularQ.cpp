#include <iostream>
using namespace std;

//variable
#define size 10
int A [size];
int front = -1, rear= -1;

bool isEmpty(){
    if (front == -1 && rear == -1){
        return true;
    }
    else{
        return false;
    };
}

void enqueue(int value){
    if ((rear + 1)% size == front){
        cout << "queue is full";
    }
    else {
        if(front == -1){
            front = 0;
        }
        rear = (rear + 1) % size;
        A[rear] = value;
    }
}

void dequeue(){
    if (isEmpty()){
        cout << "queue is empty";
    }
    else{
        if (front == rear){
            front = rear = -1;
        }
        else{
            front = (front + 1) % size;
        }
    }
}

void showFront(){
    if (isEmpty()){
        cout << "queue is empty";
    }
    else{
        cout << A[front];
    }
}

void displayQueue(){
    if (isEmpty()){
        cout << "queue is empty";
    }
    else{
        if (front <= rear)
        {
            for (int i = front; i <= rear; i++){
                cout << A[i] << " ";
            }
        }
        else{
            int i = front;
            while (i < size){
                cout<<A[i]<<" ";
                i++;
            }
            int j = 0;
            while ( j<= rear)
            {
                cout<<A[j]<<" ";
                j++;
            }
            
        }
    }
}


int main()
{
     int choice, flag=1, value;
 while( flag == 1)
 {
  cout<<"\n1.enqueue 2.dequeue 3.showfront 4.displayQueue 5.exit\n";
  cin>>choice;
  switch (choice)
  {
  case 1: cout<<"Enter Value:\n";
          cin>>value;
          enqueue(value);
          break;
  case 2: dequeue();
          break;
  case 3: showFront();
          break;
  case 4: displayQueue();
          break;
  case 5: flag = 0;
          break;
  }
 }

    return 0;
}