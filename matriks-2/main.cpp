#include <iostream>
using namespace std;

int main() {
    // proses inputan user
    int baris, kolom;
    cout << "Masukkan jumlah baris: ";
    cin >> baris;
    cout << "Masukkan jumlah kolom: ";
    cin >> kolom;

    // Deklarasi matriks
    int matriksA[baris][kolom],
        matriksB[baris][kolom],
        hasil[baris][kolom];

    // Proses pembuatan matriks A
    cout << "Masukkan elemen matriks A:\n";
    for (int i = 0; i < baris; i++) {
        for (int j = 0; j < kolom; j++) {
            cout << "A[" << i << "][" << j << "]: ";
            cin >> matriksA[i][j];
        }
    }


// Proses pembuatan matriks B
    cout << "Masukkan elemen matriks B:\n";
    for (int i = 0; i < baris; i++) {
        for (int j = 0; j < kolom; j++) {
            cout << "B[" << i << "][" << j << "]: ";
            cin >> matriksB[i][j];
        }
    }

    // Proses penjumlahan matriks A Dan matriks B
    for (int i = 0; i < baris; i++) {
        for (int j = 0; j < kolom; j++) {
            hasil[i][j] = matriksA[i][j] * matriksB[i][j];
        }
    }

    // Hasil dari penjumlahan matriks A dan matriks B
    cout << "Hasil penjumlahan matriks:\n";
    for (int i = 0; i < baris; i++) {
        for (int j = 0; j < kolom; j++) {
            cout << hasil[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}


