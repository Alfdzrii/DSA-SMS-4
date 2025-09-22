#include <iostream>
using namespace std;

const int MAX_SIZE = 10;

class Stack {
private:
    // Array to store stack elements
    int arr[MAX_SIZE];

    // Variable to track the top of the stack. -1 means the stack is empty.
    int top;

public:
    // Constructor to initialize the stack
    Stack() {
        top = -1;
    }
    // Function to add an element to the top of the stack
    void push(int value) {
        if (top >= MAX_SIZE - 1) {
            cout << "Stack Overflow! Cannot push value." << endl;
            return;
        }
        arr[++top] = value;
        cout << value << " pushed to stack." << endl;
    }

    // Function to remove an element from the top of the stack
    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow! Cannot pop from an empty stack." << endl;
            return -1;
        }
        return arr[top--];
    }

    // Function to view the top element without removing it
    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return -1;
        }
        return arr[top];
    }

    // Function to check if the stack is empty
    bool isEmpty() {
        return (top < 0);
    }
};


// --- Main function to demonstrate stack usage ---
int main() {
    Stack myStack;

    cout << "--- Pushing elements ---" << endl;
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);

    cout << "\n--- Peeking at the top ---" << endl;
    cout << "Top element is: " << myStack.peek() << endl;

    cout << "\n--- Popping elements ---" << endl;
    // Pop all elements until the stack is empty
    while (!myStack.isEmpty()) {
        cout << myStack.pop() << " popped from stack." << endl;
    }
    
    // Try to pop from an empty stack to see the underflow message
    myStack.pop();

    return 0;
}