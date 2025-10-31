#include <iostream>

using namespace std;

// 1. Definisikan struktur untuk Node (simpul)
// Setiap node punya dua bagian: data dan penunjuk (pointer) ke node berikutnya.
struct Node {
    int data;       // Data yang disimpan (misal: angka)
    Node* next;     // Pointer ke Node selanjutnya

    // Constructor untuk memudahkan pembuatan node baru
    Node(int val) {
        data = val;
        next = nullptr; // Awalnya, node baru tidak menunjuk ke mana-mana
    }
};

// Fungsi untuk mencetak semua elemen dalam linked list
void printList(Node* head) {
    Node* temp = head; // Mulai dari node pertama
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next; // Pindah ke node berikutnya
    }
    cout << "NULL" << endl;
}

int main() {
    // 'head' adalah pointer yang selalu menunjuk ke node pertama.
    // Awalnya, list kita kosong, jadi head menunjuk ke NULL.
    Node* head = nullptr;

    cout << "Membuat Linked List..." << endl;

    // --- Menambahkan elemen ke awal list ---

    // Buat node baru dengan data 30
    Node* newNode1 = new Node(30);
    head = newNode1; // Karena ini elemen pertama, head menunjuk ke sini
    cout << "List saat ini: ";
    printList(head);

    // Tambah node baru lagi dengan data 20
    Node* newNode2 = new Node(20);
    newNode2->next = head; // Sambungkan node baru (20) ke node pertama yg lama (30)
    head = newNode2;       // Jadikan node baru (20) sebagai head yang baru
    cout << "List saat ini: ";
    printList(head);

    // Tambah node baru lagi dengan data 10
    Node* newNode3 = new Node(10);
    newNode3->next = head; // Sambungkan node baru (10) ke node pertama yg lama (20)
    head = newNode3;       // Jadikan node baru (10) sebagai head yang baru
    cout << "List saat ini: ";
    printList(head);

    return 0;
}