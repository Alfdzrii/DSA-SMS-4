#include <iostream>
using namespace std;

int main() {
    // Deklarasikan array dengan ukuran 9 (indeks 0-8)
    const int UKURAN_ARRAY = 9;
    int array[UKURAN_ARRAY];
    
    // Loop harus berjalan dari 0 hingga UKURAN_ARRAY - 1
    for (int i = 0; i < UKURAN_ARRAY; i++) {
        cout << "Masukkan angka untuk indeks ke-" << i << ": ";
        cin >> array[i];
    }

    // Cetak semua isi array untuk verifikasi
    cout << "\nIsi array Anda adalah: ";
    for (int i = 0; i < UKURAN_ARRAY; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    return 0;
}