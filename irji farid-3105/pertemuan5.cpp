#include <iostream>
using namespace std;
int main() {
bool a;
a = 2 == 2;
cout << std::boolalpha << a << endl; // true
a = 3 != 2;
cout << std::boolalpha << a << endl; // false
a = 2 < 3;
cout << std::boolalpha << a << endl; // true
a = 3 > 2;
cout << std::boolalpha << a << endl; // false
a = 3 <= 1;
cout << std::boolalpha << a << endl; // true
a = 2 >= 4;
cout << std::boolalpha << a << endl; // true
return 0;
}
