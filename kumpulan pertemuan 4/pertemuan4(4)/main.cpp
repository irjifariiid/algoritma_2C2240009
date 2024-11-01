#include <iostream>
using namespace std;

int main() {
    const int maxUkuran = 10;   // Ukuran maksimum array
    int angka[maxUkuran];       // Deklarasi array dengan ukuran maksimum 10
    int Neff = 0;               // Neff awalnya 0 (tidak ada elemen yang digunakan)

    // Mengisi Neff elemen pada array
    cout << "Masukkan jumlah elemen yang ingin digunakan (max 10): ";
    cin >> Neff;

    // Validasi Neff
    if (Neff > maxUkuran || Neff < 0) {
        cout << "Jumlah elemen tidak valid!";
        return 1; // Menghentikan program jika input Neff tidak valid
    }

    // Mengisi nilai untuk Neff elemen pertama dari array
    for (int i = 0; i < Neff; i++) {
        cout << "Masukkan angka untuk indeks " << i << ": ";
        cin >> angka[i];
    }

    // Menampilkan Neff elemen array
    cout << "Isi array berdasarkan Neff (" << Neff << " elemen): ";
    for (int i = 0; i < Neff; i++) {
        cout << angka[i] << " ";
    }

    return 0;
}
