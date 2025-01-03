#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

int main() {
    double a, b, c, diskriminan, x1, x2;
    ofstream file;

    // Meminta input koefisien a, b, dan c dari pengguna
    cout << "Masukkan koefisien a, b, dan c untuk persamaan ax^2 + bx + c = 0: ";
    cin >> a >> b >> c;

    // Memeriksa apakah a sama dengan 0
    if (a == 0) {
        cout << "Persamaan bukan persamaan kuadrat." << endl;
        return 1;
    }

    // Menghitung diskriminan
    diskriminan = b * b - 4 * a * c;

    // Membuka file untuk menulis hasil
    file.open("hasil_persamaan.txt");

    // Menulis hasil ke file
    if (diskriminan > 0) {
        x1 = (-b + sqrt(diskriminan)) / (2 * a);
        x2 = (-b - sqrt(diskriminan)) / (2 * a);
        file << "Akar persamaan:" << endl;
        file << "x1 = " << x1 << endl;
        file << "x2 = " << x2 << endl;
    } else if (diskriminan == 0) {
        x1 = -b / (2 * a);
        file << "Akar persamaan (kembar):" << endl;
        file << "x1 = x2 = " << x1 << endl;
    } else {
        file << "Persamaan tidak memiliki akar real." << endl;
    }

    // Menutup file
    file.close();

    cout << "Hasil perhitungan telah disimpan dalam file hasil_persamaan.txt" << endl;

    return 0;
}
