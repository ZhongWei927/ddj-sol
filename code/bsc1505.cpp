#include <iostream>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    string p, q;
    cin >> p >> q;
    q += "six";

    int frequency_p[26] = {}, frequency_q[26] = {};

    for (int i=0;i<a;i++) {
        frequency_p[p[i]-'A']++;
    }
    for (int i=0;i<b+3;i++) {
        frequency_q[q[i]-'A']++;
    }

    for (int i=0;i<26;i++) {
        if (frequency_p[i] != frequency_q[i]) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
}