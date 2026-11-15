#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int q; cin>>q;

    vector<int> l(6), r(6);
    for (int i=2;i>=0;i--) cin >> l[i] >> l[5-i] >> r[i] >> r[5-i];

    int up = 0, down = 0, last, serve = -1;
    while (last = serve, q--) {
        if (cin >> serve, serve != last and last != -1) serve? down++: up++;
    }
    
    for (int i=0;i<3;i++) cout << l[(6 - up % 6 + i) % 6] << " \n"[i == 2];
    for (int i=5;i>=3;i--) cout << l[(6 - up % 6 + i) % 6] << " \n"[i == 3];
    for (int i=0;i<3;i++) cout << r[(6 - down % 6 + i) % 6] << " \n"[i == 2];
    for (int i=5;i>=3;i--) cout << r[(6 - down % 6 + i) % 6] << " \n"[i == 3];
}