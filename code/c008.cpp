#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    while (m > 0) {
        int temp = m;
        m = n % m;
        n = temp;
    }

    if (n == 1) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}