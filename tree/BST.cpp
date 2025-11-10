#include <iostream>
using namespace std;

const int SPACING = 10;

struct Snode
{
    int data;
    int occ;
    Snode *left, *right;
};


// insert data code
Snode *insert (int dat, Snode *T)
{
    Snode *temp;
    if (!T){
        temp = new Snode;
        temp -> data = dat;
        temp -> left = 0;
        temp -> right = 0;
        temp -> occ = 1;
        return temp;
    }
    else{
        if(dat < T -> data)
            T->left = insert(dat, T->left);
        else if (dat > T -> data)
            T -> right = insert(dat, T -> right);
        else
            T ->occ++;
        return T;
    }
}

Snode *findMin (Snode *T){
    if (!T)
        return 0;

    while(T->left != 0)
        T = T->left;
    
        return T;
}

Snode *Del (int dat, Snode *T){
    Snode *cur;
    if (!T)
        return 0;
    
    if (dat < T ->data)
        T->left =  Del(dat, T->left);
    else if (dat > T -> data)
        T -> right = Del(dat, T->right);
    else{
        if (T->occ > 0){
            T->occ--;
            return T;
        }
        if (T->left && T->right){
            Snode*temp = findMin(T->right);
            T->data = temp->data;
            T->occ = temp ->occ;
            T->right = Del(temp->data, T->right);
        }
        else if(T->left)
        {
            cur = T;
            T = T->left;
            delete cur;
        }
        else {
            cur = T;
            T = T->right; 
            delete cur;
        }
    }
    return T;
};

void printTree(Snode *root, int space){
    if (root==0) return;

    space+=SPACING;
    printTree (root -> right, space);
    cout << endl;
    for (int i = SPACING ; i < space; i++)
        cout <<" ";
    
    cout << "["<< root ->data << "(" << root -> occ <<")}"<<"\n";
}

int main() {
    Snode *root = 0; 
    int choice;
    int data;

    while (true) {
        cout << "\n--- MENU BINARY SEARCH TREE ---" << endl;
        cout << "1. Insert Data" << endl;
        cout << "2. Delete Data" << endl;
        cout << "0. Exit" << endl;
        cout << "-------------------------------" << endl;
        cout << "choose: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "insert the data: ";
                cin >> data;
                root = insert(data, root); 
                cout << "Data " << data << " Success to insert." << endl;

                // === [PERUBAHAN] TAMPILKAN POHON OTOMATIS ===
                cout << "\n--- Pohon Saat Ini (diputar 90 derajat) ---" << endl;
                if (root == 0) {
                    cout << "(Pohon masih kosong)" << endl;
                } else {
                    printTree(root, 0); // Panggil fungsi printTree
                }
                cout << "\n------------------------------------------" << endl;
                break;

            // --- CASE 2: DELETE ---
            case 2:
                cout << "delete data: ";
                cin >> data;
                root = Del(data, root); 
                cout << "Data " << data << " Success full to delete the data." << endl;
                
                // === [PERUBAHAN] TAMPILKAN POHON OTOMATIS ===
                cout << "\n--- tree right now (rotate 90 degree) ---" << endl;
                if (root == 0) {
                    cout << "(the tree is empty)" << endl;
                } else {
                    printTree(root, 0); // Panggil fungsi printTree
                }
                cout << "\n------------------------------------------" << endl;
                break;
            
            // --- CASE 0: EXIT ---
            case 0:
                cout << "The program has been stopped." << endl;
                return 0; 

            // --- DEFAULT: PILIHAN TIDAK VALID ---
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
                break;
        }
    }

    return 0; 
}