#include <iostream>
using namespace std;

int main() {
    //proses inputan user
    int baris, kolom;
    cout << "Masukkan jumlah baris: ";
    cin >> baris;
    cout << "Masukkan jumlah kolom: ";
    cin >> kolom;

    // Deklarasi matriks
    int matriks[baris][kolom],
        transpose[kolom][baris];

    // Proses pembuatan matriks
    cout << "Masukkan elemen matriks:\n";
    for (int i = 0; i < baris; i++) {
        for (int j = 0; j < kolom; j++) {
            cout << "Elemen [" << i << "][" << j << "]: ";
            cin >> matriks[i][j];
        }
    }

    // Proses transpose matriks
    for (int i = 0; i < baris; i++) {
        for (int j = 0; j < kolom; j++) {
            transpose[j][i] = matriks[i][j];
        }
    }

    cout << "\nMatriks sebelum ditranspose:\n";
    for (int i = 0; i < baris; i++) {
        for (int j = 0; j < kolom; j++) {
            cout << matriks[i][j] << " ";
        }
        cout << endl;
    }

    // Menampilkan hasil matriks yang sudah di transpose
    cout << "\nMatriks sesudah distranspose:\n";
    for (int i = 0; i < kolom; i++) {
        for (int j = 0; j < baris; j++) {
            cout << transpose[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}


