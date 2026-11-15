#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int q; cin>>q;

    deque<int> l(6), r(6);
    for (int i=2;i>=0;i--) cin >> l[i] >> l[5-i] >> r[i] >> r[5-i];

    int last, serve = -1;
    while (last = serve, q--) {
        if (cin>>serve, serve != last and last != -1) {
            if (serve) {
                l.push_front(l.back());
                l.pop_back();
            } else {
                r.push_front(r.back());
                r.pop_back();
            }
        }
    }
    
    for (int i=0;i<3;i++) cout << l[i] << " \n"[i == 2];
    for (int i=5;i>=3;i--) cout << l[i] << " \n"[i == 3];
    for (int i=0;i<3;i++) cout << r[i] << " \n"[i == 2];
    for (int i=5;i>=3;i--) cout << r[i] << " \n"[i == 3];
}