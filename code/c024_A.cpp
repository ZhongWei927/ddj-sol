#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n; cin>>n;
    vector<pair<int, int>> a;

    int res1 = 0, res2 = 0, res3 = 0, res4 = 0;

    for (int i=0, type=-1, streak=0; i<=n; i++) {
        int k = type ^ 1;
        if (i < n) cin>>k;

        if (k != type) {
            if (streak) {
                a.push_back({type, streak});
                if (!k) res1 += streak / 2;
            }
            streak = 0;
        }
        type = k; streak++;
    }

    int quota = (a.front().first and !(a.front().second % 2));
    for (auto&x:a) {
        int ends = (&x == &a.front()) + (&x == &a.back());

        if (!x.first) {
            res2 += (x.second - 1 + ends) / 2;
            res3 += (x.second + ends) / 3;
        } else if (&x != &a.front()) {
            bool oneleft = (&x - 1 == &a.front() and (&x - 1)->second % 2 == 1) or
                (&x - 1 != &a.front() and (&x - 1)->second % 2 == 0);

            if (quota == 1 and oneleft) {
                res4++; quota = x.second % 2 == 0;
            } else {
                quota += x.second % 2 == 0;
                if (quota == 2 or quota == 1 and oneleft) {
                    res4++; quota = 0;
                } else {
                    quota = x.second % 2 == 0;
                }
            }
        }
    }
    if (a.back().first == 0 and a.back().second % 2 == 1 and quota == 1)
        res4++;

    cout << res1 << ' ' << res2 << ' ' << res3 << ' ' << res2+res4 << '\n';
}