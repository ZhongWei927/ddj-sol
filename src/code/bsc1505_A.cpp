#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    string p, q;
    cin >> p >> q;
    q += "six";

    sort(p.begin(), p.end());
    sort(q.begin(), q.end());

    if (p == q) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}