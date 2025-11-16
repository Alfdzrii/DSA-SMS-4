#include <iostream>
#include <string>
using namespace std;

struct Tree {
    Tree *FC;  // First Child
    Tree *NS;  // Next Sibling
    string name;
    int size;
    bool isFile;
};

// add new node
Tree* createNode(string name, int size = 0, bool isFile = false) {
    Tree* node = new Tree;
    node->name = name;
    node->size = size;
    node->isFile = isFile;
    node->FC = NULL;
    node->NS = NULL;
    return node;
}

// leaf counting
int CountLeaves(Tree *t) {
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

// leaf Pre-order
int DisplayLeavesPreOrder(Tree *t, int depth = 0) {
    if (!t) {
        return 0;
    }
    
    int count = 0;
    
    // Print indentation
    for (int i = 0; i < depth; i++) {
        cout << "  ";
    }
    
    cout << t->name;
    
    if (!(t->FC)) {
        cout << " [LEAF]";
        if (t->isFile && t->size > 0) {
            cout << " (size: " << t->size << ")";
        }
        cout << endl;
        count = 1;
    }
    else {
        cout << " [DIR]" << endl;
        count = DisplayLeavesPreOrder(t->FC, depth + 1);
    }
    
    count += DisplayLeavesPreOrder(t->NS, depth);
    
    return count;
}

// leaf listing
void ListOnlyLeaves(Tree *t, int depth = 0) {
    if (!t) {
        return;
    }   
    if (!(t->FC)) {
        for (int i = 0; i < depth; i++) {
            cout << "  ";
        }
        cout << "- " << t->name;
        if (t->isFile && t->size > 0) {
            cout << " (" << t->size << " bytes)";
        }
        cout << endl;
    }
    else {
        ListOnlyLeaves(t->FC, depth + 1);
    }
    
    ListOnlyLeaves(t->NS, depth);
}

int main() {
    
    Tree *root = createNode("usr", 0, false);
    
    Tree *mark = createNode("mark", 0, false);
    root->FC = mark;
    
    Tree *book = createNode("book", 0, false);
    mark->FC = book;
    
    Tree *c1r = createNode("c1.r", 3, true);
    book->FC = c1r;
    c1r->NS = createNode("c2.r", 2, true);
    c1r->NS->NS = createNode("c3.r", 4, true);
    
    Tree *crs1 = createNode("crs1", 0, false);
    book->NS = crs1;
    
    Tree *cop3530 = createNode("cop3530", 0, false);
    crs1->FC = cop3530;
    
    Tree *fal88 = createNode("fal88", 1, true);
    cop3530->FC = fal88;
    fal88->NS = createNode("spr89", 2, true);
    fal88->NS->NS = createNode("sum89", 3, true);
    fal88->NS->NS->NS = createNode("syl.r", 12, true);
    
    Tree *alex = createNode("alex", 0, false);
    mark->NS = alex;
    
    Tree *junk1 = createNode("junk.c", 6, true);
    alex->FC = junk1;
    junk1->NS = createNode("junk.c", 30, true);
    
    Tree *bill = createNode("bill", 0, false);
    alex->NS = bill;
    
    Tree *work = createNode("work", 0, false);
    bill->FC = work;
    
    Tree *crs2 = createNode("crs2", 0, false);
    work->FC = crs2;
    
    Tree *cop3212 = createNode("cop3212", 0, false);
    crs2->FC = cop3212;
    
    Tree *fal88_2 = createNode("fal88", 9, true);
    cop3212->FC = fal88_2;
    
    
    cout << "============================================" << endl;
    cout << "   TREE STRUCTURE WITH LEAF INDICATORS" << endl;
    cout << "============================================" << endl;
    int totalLeaves = DisplayLeavesPreOrder(root);
    cout << endl;
    
    cout << "============================================" << endl;
    cout << "   TOTAL LEAF NODES: " << totalLeaves << endl;
    cout << "============================================" << endl;
    cout << endl;
    
    cout << "============================================" << endl;
    cout << "   LIST OF LEAF NODES ONLY" << endl;
    cout << "============================================" << endl;
    ListOnlyLeaves(root);
    cout << endl;
    
    int count = CountLeaves(root);
    cout << "Verification - Total Leaves: " << count << endl;
    
    return 0;
}