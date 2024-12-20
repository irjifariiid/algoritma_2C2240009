#include <iostream>
using namespace std;

int main() {
    int baris, kolom;

    // Input jumlah baris dan kolom matriks
    cout << "Masukkan jumlah baris: ";
    cin >> baris;
    cout << "Masukkan jumlah kolom: ";
    cin >> kolom;

    int matriks[baris][kolom];  // Deklarasi matriks

    // Input elemen-elemen matriks
    cout << "Masukkan elemen-elemen matriks:" << endl;
    for (int i = 0; i < baris; i++) {
        for (int j = 0; j < kolom; j++) {
            cin >> matriks[i][j];
        }
    }

    // Inisialisasi nilai maksimum dan minimum
    int max = matriks[0][0];
    int min = matriks[0][0];
    int maxBaris = 0, maxKolom = 0;
    int minBaris = 0, minKolom = 0;

    // Mencari elemen maksimum dan minimum serta posisinya
    for (int i = 0; i < baris; i++) {
        for (int j = 0; j < kolom; j++) {
            if (matriks[i][j] > max) {
                max = matriks[i][j];
                maxBaris = i;
                maxKolom = j;
            }
            if (matriks[i][j] < min) {
                min = matriks[i][j];
                minBaris = i;
                minKolom = j;
            }
        }
    }

    // Output nilai maksimum dan minimum serta posisinya
    cout << "Nilai maksimum: " << max << " pada posisi (Baris: " << maxBaris + 1 << ", Kolom: " << maxKolom + 1 << ")" << endl;
    cout << "Nilai minimum: " << min << " pada posisi (Baris: " << minBaris + 1 << ", Kolom: " << minKolom + 1 << ")" << endl;

    return 0;
}
