#include <iostream>
#include <vector>

// Standar namespace yang digunakan
using namespace std;

// ====================================================================
// BAGIAN 1: Circular Array (Queue)
// ====================================================================

class CircularQueue {
private:
    int* arr;
    int capacity;
    int front;
    int rear;
    int count; // Jumlah elemen saat ini

public:
    // Constructor untuk inisialisasi queue
    CircularQueue(int size) {
        capacity = size;
        arr = new int[capacity];
        front = -1; // -1 menunjukkan queue kosong
        rear = -1;
        count = 0;
    }

    // Destructor untuk membersihkan memori
    ~CircularQueue() {
        delete[] arr;
    }

    // Fungsi untuk menambah elemen (enqueue)
    void enqueue(int value) {
        if (isFull()) {
            cout << "-> Operasi Gagal: Queue penuh (Overflow)." << endl;
            return;
        }
        if (isEmpty()) {
            front = 0;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = value;
        count++;
        cout << "-> Enqueue " << value << " berhasil. | front: " << front << ", rear: " << rear << ", count: " << count << endl;
    }

    // Fungsi untuk menghapus elemen (dequeue)
    void dequeue() {
        if (isEmpty()) {
            cout << "-> Operasi Gagal: Queue kosong (Underflow)." << endl;
            return;
        }
        cout << "-> Dequeue elemen " << arr[front] << " berhasil. | ";
        if (front == rear) { // Jika hanya ada satu elemen
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % capacity;
        }
        count--;
        cout << "front: " << getFrontIndex() << ", rear: " << getRearIndex() << ", count: " << count << endl;
    }
    
    // Mengecek apakah queue penuh
    bool isFull() {
        return count == capacity;
    }

    // Mengecek apakah queue kosong
    bool isEmpty() {
        return count == 0;
    }

    // Getter untuk mendapatkan nilai
    int getCapacity() { return capacity; }
    int getFrontIndex() { return front; }
    int getRearIndex() { return rear; }
    int getCount() { return count; }

    // Fungsi untuk setup state sesuai input user
    void setupInitialState(int f, const vector<int>& elements) {
        if (elements.size() > capacity || f >= capacity) {
            cout << "Input tidak valid! Jumlah elemen melebihi kapasitas atau front di luar batas." << endl;
            return;
        }
        front = f;
        count = elements.size();
        if (count == 0) {
            front = -1;
            rear = -1;
            return;
        }
        for(size_t i = 0; i < count; ++i) {
            int index = (front + i) % capacity;
            arr[index] = elements[i];
        }
        rear = (front + count - 1) % capacity;
    }
};

// BAGIAN 2: Linked List (Queue)
struct Node {
    int data;
    Node* next;
};

class LinkedQueue {
private:
    Node* front;
    Node* rear;

public:
    // Constructor
    LinkedQueue() {
        front = nullptr;
        rear = nullptr;
    }

    // Operasi Enqueue
    void enqueue(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;
        
        if (rear == nullptr) {
            front = newNode;
            rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        cout << "-> Elemen " << value << " berhasil ditambahkan." << endl;
    }

    // Menampilkan isi queue
    void display() {
        if (front == nullptr) {
            cout << "-> Queue kosong." << endl;
            return;
        }
        Node* temp = front;
        cout << "-> Isi Queue: [FRONT] ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "[REAR]" << endl;
    }
};


void simulateCircularQueue() {
    cout << "### SOAL 1: SIMULASI CIRCULAR ARRAY INTERAKTIF ###" << endl;
    cout << "-------------------------------------------------" << endl;

    int capacity, initialCount, initialFront;
    cout << "Masukkan kapasitas array: ";
    cin >> capacity;
    cout << "Masukkan posisi awal pointer front: ";
    cin >> initialFront;
    cout << "Masukkan jumlah elemen awal dalam array: ";
    cin >> initialCount;

    vector<int> initialElements;
    for (int i = 0; i < initialCount; ++i) {
        int val;
        cout << "Masukkan elemen ke-" << i + 1 << ": ";
        cin >> val;
        initialElements.push_back(val);
    }

    CircularQueue cq(capacity);
    cq.setupInitialState(initialFront, initialElements);

    cout << "\n--- Analisis Keadaan Awal ---" << endl;
    cout << "a) Kapasitas array adalah: " << cq.getCapacity() << endl;
    cout << "b) Nilai rear pointer adalah: " << cq.getRearIndex() << endl;
    int spaceLeft = cq.getCapacity() - cq.getCount();
    cout << "c) Butuh " << spaceLeft << " operasi insert lagi untuk membuat array penuh." << endl;
    cout << "d) Nilai rear adalah: " << cq.getRearIndex() << endl;
    cout << "Nilai front adalah: " << cq.getFrontIndex() << endl;
    
    cout << "\n--- Simulasi Operasi ---" << endl;
    int deleteOps, insertOps;
    cout << "e) Masukkan jumlah operasi delete (dequeue) yang akan dilakukan: ";
    cin >> deleteOps;
    cout << "   Masukkan jumlah operasi insert (enqueue) yang akan dilakukan: ";
    cin >> insertOps;

    cout << "\n--- Melakukan " << deleteOps << "x Dequeue ---" << endl;
    for (int i = 0; i < deleteOps; ++i) {
        cq.dequeue();
    }

    cout << "\n--- Melakukan " << insertOps << "x Enqueue ---" << endl;
    for (int i = 0; i < insertOps; ++i) {
        if (cq.isFull()) {
             cout << "-> Operasi Gagal: Queue penuh (Overflow)." << endl;
             continue;
        }
        int val;
        cout << "Masukkan nilai untuk di-enqueue: ";
        cin >> val;
        cq.enqueue(val);
    }

    cout << "\n--- Hasil Akhir Setelah Semua Operasi ---" << endl;
    cout << "Nilai akhir front: " << cq.getFrontIndex() << endl;
    cout << "Nilai akhir rear: " << cq.getRearIndex() << endl;
}

void simulateLinkedListQueue() {
    cout << "\n\n### SOAL 2: SIMULASI LINKED LIST QUEUE INTERAKTIF ###" << endl;
    cout << "----------------------------------------------------" << endl;
    
    LinkedQueue lq;
    int choice;
    do {
        cout << "\nMenu Operasi:" << endl;
        cout << "1. Enqueue (Tambah Elemen)" << endl;
        cout << "2. Display (Tampilkan Queue)" << endl;
        cout << "0. Selesai & Keluar" << endl;
        cout << "Pilihan Anda: ";
        cin >> choice;

        switch(choice) {
            case 1: {
                int value;
                cout << "  Masukkan nilai integer yang akan di-enqueue: ";
                cin >> value;
                lq.enqueue(value);
                break;
            }
            case 2:
                lq.display();
                break;
            case 0:
                cout << "Simulasi selesai." << endl;
                break;
            default:
                cout << "Pilihan tidak valid, silakan coba lagi." << endl;
                break;
        }
    } while (choice != 0);
}

int main() {
    // Menjalankan simulasi untuk soal 1
    simulateCircularQueue();

    // Menjalankan simulasi untuk soal 2
    simulateLinkedListQueue();
    
    return 0;
}