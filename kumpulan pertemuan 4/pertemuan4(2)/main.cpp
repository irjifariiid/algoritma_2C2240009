#include <iostream>
#include <string>
using namespace std;

int main() {
    string s1[] = {"Hello"};

    // Tidak bisa mengubah karakter dalam string s1 langsung pada indeks tertentu, ini akan menyebabkan error.
    // s1[1] = 'a'; // -> ini tidak diizinkan dan akan menyebabkan error

    // Namun, kita bisa membaca nilai string melalui indeks, misalnya:
    cout << "Karakter kedua pada string s1 adalah: " << s1[0] << endl;

    return 0;
}
