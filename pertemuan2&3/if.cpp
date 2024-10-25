#include <iostream> 
#include <string>  // Untuk menggunakan fungsi to_string 
 
using namespace std; 
 
int main() { 
    int N; 
 
    cout << "Masukkan nilai N: "; 
    cin >> N; 
 
    if (N > 0) { 
        cout << to_string(N) + " bilangan positif" << endl; 
    } else { 
        cout << to_string(N) + " bilangan bukan positif" << endl; 
    } 
 
    return 0; 
} 