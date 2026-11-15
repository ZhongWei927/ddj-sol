#include <iostream>

using namespace std;

int main() {
    int q;
    cin>>q;

    int l[6], r[6];
    for (int i=2;i>=0;i--) {
        cin >> l[i] >> l[5-i] >> r[i] >> r[5-i];
    }

    int last = -1, down = 0, up = 0;
    while (q--) {
        int serve;
        cin >> serve;

        if (serve != last and last != -1) {
            if (serve == 0) {
                up++;
            } else {
                down++;
            }
        }
        last = serve;
    }

    for (int i=0;i<3;i++) {
        cout << l[(6 - up % 6 + i) % 6] << ' ';
    }
    cout << endl;

    for (int i=5;i>=3;i--) {
        cout << l[(6 - up % 6 + i) % 6] << ' ';
    }
    cout << endl;

    for (int i=0;i<3;i++) {
        cout << r[(6 - down % 6 + i) % 6] << ' ';
    }
    cout << endl;

    for (int i=5;i>=3;i--) {
        cout << r[(6 - down % 6 + i) % 6] << ' ';
    }
    cout << endl;
}