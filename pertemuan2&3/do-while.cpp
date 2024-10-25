#include <iostream>
using namespace std;

int main() {
    int a, b;

    // Meminta input dari user untuk nilai a dan b
    cout << "Masukkan nilai a: ";
    cin >> a;
    cout << "Masukkan nilai b: ";
    cin >> b;

    // Menggunakan perulangan do-while untuk mencetak dari a hingga b
    do {
        cout << a << ' '<< " aku cinta rektor aku "<< endl;  // Menampilkan nilai a
        a++;               // Menambahkan a sebesar 1 setiap iterasi
    } while (a <= b);      // Kondisi dicek setelah setiap iterasi

    return 0;
}

