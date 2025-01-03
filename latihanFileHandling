#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip> // Untuk mengatur format output

using namespace std;

int main() {
    double a, b, c;

    // Meminta input dari pengguna
    cout << "Masukkan koefisien a, b, dan c untuk persamaan ax^2 + bx + c = 0: ";
    cin >> a >> b >> c;

    // Validasi jika a = 0
    if (a == 0) {
        cout << "Nilai a tidak boleh 0. Ini bukan persamaan kuadrat." << endl;
        return 0;
    }

    // Menghitung diskriminan
    double D = b * b - 4 * a * c;

    // Membuka file untuk menyimpan hasil
    ofstream outfile("hasil_persamaan.txt");
    if (!outfile) {
        cerr << "Gagal membuka file untuk menulis hasil." << endl;
        return 1;
    }

    // Menghitung akar-akar atau memberikan pesan sesuai nilai diskriminan
    if (D > 0) {
        double x1 = (-b + sqrt(D)) / (2 * a);
        double x2 = (-b - sqrt(D)) / (2 * a);
        outfile << fixed << setprecision(2); // Format 2 desimal
        outfile << "Akar persamaan: x1 = " << x1 << ", x2 = " << x2 << endl;
        cout << "Hasil telah disimpan dalam file 'hasil_persamaan.txt'." << endl;
    } else if (D == 0) {
        double x = -b / (2 * a);
        outfile << fixed << setprecision(2); // Format 2 desimal
        outfile << "Akar persamaan: x1 = x2 = " << x << endl;
        cout << "Hasil telah disimpan dalam file 'hasil_persamaan.txt'." << endl;
    } else {
        outfile << "Persamaan tidak memiliki akar real." << endl;
        cout << "Hasil telah disimpan dalam file 'hasil_persamaan.txt'." << endl;
    }

    outfile.close();
    return 0;
}
