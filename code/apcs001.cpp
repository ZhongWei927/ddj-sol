#include <iostream>

using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    bool flag = true;
    if (((a > 0) & (b > 0)) == (c > 0)) {
        cout << "AND" << endl;
        flag = false;
    }
    if (((a > 0) | (b > 0)) == (c > 0)) {
        cout << "OR" << endl;
        flag = false;
    }
    if (((a > 0) ^ (b > 0)) == (c > 0)) {
        cout << "XOR" << endl;
        flag = false;
    }

    if (flag) {
        cout << "IMPOSSIBLE" << endl;
    }
}