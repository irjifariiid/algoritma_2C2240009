#include <iostream>

using namespace std;

int main() {
    int barisA, kolomA, barisB, kolomB;

    // Input ukuran matriks A
    cout << "Masukkan jumlah baris matriks A: ";
    cin >> barisA;
    cout << "Masukkan jumlah kolom matriks A: ";
    cin >> kolomA;

    // Input ukuran matriks B
    cout << "Masukkan jumlah baris matriks B: ";
    cin >> barisB;
    cout << "Masukkan jumlah kolom matriks B: ";
    cin >> kolomB;

    // Validasi ukuran matriks
    if (barisA != barisB || kolomA != kolomB) {
        cout << "Ukuran matriks harus sama untuk dapat dijumlahkan!" << endl;
        return 1; // Keluar dari program dengan kode kesalahan
    }

    // Deklarasi matriks A dan B
    int matriksA[barisA][kolomA], matriksB[barisB][kolomB], hasil[barisA][kolomA];

    // Input elemen matriks A dan B
    cout << "Masukkan elemen matriks A:" << endl;
    for (int i = 0; i < barisA; i++) {
        for (int j = 0; j < kolomA; j++) {
            cin >> matriksA[i][j];
        }
    }

    cout << "Masukkan elemen matriks B:" << endl;
    for (int i = 0; i < barisB; i++) {
        for (int j = 0; j < kolomB; j++) {
            cin >> matriksB[i][j];
        }
    }

    // Penjumlahan matriks
    for (int i = 0; i < barisA; i++) {
        for (int j = 0; j < kolomA; j++) {
            hasil[i][j] = matriksA[i][j] + matriksB[i][j];
        }
    }

    // Tampilkan hasil penjumlahan
    cout << "Hasil penjumlahan matriks:" << endl;
    for (int i = 0; i < barisA; i++) {
        for (int j = 0; j < kolomA; j++) {
            cout << hasil[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}