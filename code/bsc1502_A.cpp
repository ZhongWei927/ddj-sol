#include <iostream>

using namespace std;

int main() {
    int x, y;
    cin >> x >> y;
    if (x & y & 1) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }
}