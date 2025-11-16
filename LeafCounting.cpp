#include <iostream>
using namespace std;

struct Tree{
    Tree *FC;  // First Child
    Tree *NS;  // Next Sibling
    int data;
    char name;
};

// counting leaf nodes
int CountLeaves(Tree *t)
{
    if (!t) {
        return 0;
    }
    
    int count = 0;
    
    if (!(t->FC)) {
        count = 1;
    }
    else {
        count = CountLeaves(t->FC);
    }
    count += CountLeaves(t->NS);
    
    return count;
}

// count leafPre-order Traversal 
int CountLeavesPreOrder(Tree *t)
{
    if (!t) {
        return 0;
    }
    
    cout << "Visit: " << t->name << " ";
    
    int count = 0;
    
    if (!(t->FC)) {
        cout << "(LEAF)" << endl;
        count = 1;
    }
    else {
        cout << "(Internal Node)" << endl;
        count = CountLeavesPreOrder(t->FC);
    }
    
    count += CountLeavesPreOrder(t->NS);
    
    return count;
}

// count leaf In-order Traversal
int CountLeavesInOrder(Tree *t)
{
    if (!t) {
        return 0;
    }
    
    int count = 0;
    
    if (!(t->FC)) {
        cout << "Visit: " << t->name << " (LEAF)" << endl;
        count = 1;
    }
    else {
        count = CountLeavesInOrder(t->FC);
        cout << "Visit: " << t->name << " (Internal Node)" << endl;
    }
    
    count += CountLeavesInOrder(t->NS);
    
    return count;
}

// count leaf Post-order Traversal
int CountLeavesPostOrder(Tree *t)
{
    if (!t) {
        return 0;
    }
    
    int count = 0;
    
    if (!(t->FC)) {
        count = 1;
        cout << "Visit: " << t->name << " (LEAF)" << endl;
    }
    else {
        count = CountLeavesPostOrder(t->FC);
        cout << "Visit: " << t->name << " (Internal Node)" << endl;
    }
    
    count += CountLeavesPostOrder(t->NS);
    
    return count;
}


// create node
Tree* createNode(char name, int data) {
    Tree* node = new Tree;
    node->name = name;
    node->data = data;
    node->FC = NULL;
    node->NS = NULL;
    return node;
}

int main()
{
    
    Tree *root = createNode('A', 1);
    root->FC = createNode('B', 2);
    root->FC->NS = createNode('C', 3);
    root->FC->NS->NS = createNode('D', 4);
    
    root->FC->FC = createNode('E', 5);
    root->FC->FC->NS = createNode('F', 6);
    
    root->FC->NS->NS->FC = createNode('G', 7);
    
    cout << "=== Menghitung Leaf Nodes ===" << endl;
    int totalLeaves = CountLeaves(root);
    cout << "Total Leaf Nodes: " << totalLeaves << endl << endl;
    
    cout << "=== Pre-order Traversal ===" << endl;
    int leavesPreOrder = CountLeavesPreOrder(root);
    cout << "Total Leaves (Pre-order): " << leavesPreOrder << endl << endl;
    
    cout << "=== In-order Traversal ===" << endl;
    int leavesInOrder = CountLeavesInOrder(root);
    cout << "Total Leaves (In-order): " << leavesInOrder << endl << endl;
    
    cout << "=== Post-order Traversal ===" << endl;
    int leavesPostOrder = CountLeavesPostOrder(root);
    cout << "Total Leaves (Post-order): " << leavesPostOrder << endl;
    
    return 0;
}