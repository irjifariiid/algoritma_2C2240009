#include <iostream>
using namespace std;

void tampilanMenu() {
    cout << "Menu Pilihan Jenis Nilai:" << endl;
    cout << "1. Tugas" << endl;
    cout << "2. UTS" << endl;
    cout << "3. UAS" << endl;
}

float hitungNilaiAkhir(float nilaiTugas, float nilaiUTS, float nilaiUAS) {
    return (nilaiTugas * 0.30) + (nilaiUTS * 0.30) + (nilaiUAS * 0.40);
}

int main() {
    float nilaiTugas, nilaiUTS, nilaiUAS;

    tampilanMenu();

    cout << "Masukkan nilai Tugas: ";
    cin >> nilaiTugas;
    cout << "Masukkan nilai UTS: ";
    cin >> nilaiUTS;
    cout << "Masukkan nilai UAS: ";
    cin >> nilaiUAS;

    float nilaiAkhir = hitungNilaiAkhir(nilaiTugas, nilaiUTS, nilaiUAS);

    cout << "Nilai Akhir: " << nilaiAkhir << endl;

    return 0;
}
