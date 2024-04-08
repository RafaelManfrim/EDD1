#include <iostream>
#include <string>

using namespace std;

int main() {
    int x = 8, y = 10; // x = 1000 ; y = 1010
    x = x ^ y; // x = 0010 ; y = 1010
    y = x ^ y; // x = 0010 ; y = 1000
    x = x ^ y; // x = 1010 ; y = 1000
    cout << "x: " << x << endl;
    cout << "y: " << y << endl;
    return 0;
}
