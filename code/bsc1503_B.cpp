#include <bits/stdc++.h>
 
using namespace std;

using ull = uint64_t;
using u128 = __uint128_t;

ull fpow(ull a, ull b, ull m) {
    ull res = 1;
    for (a %= m; b; b >>= 1, a = (u128)a * a % m)
        if (b & 1) res = (u128)res * a % m;
    return res;
}

bool comp(ull base, ull p, ull s, ull d) {
    ull res = fpow(base, d, p);
    if (res == 1 or res == p - 1) return false;
    while (--s)
        if ((res = (u128)res * res % p) == p - 1) return false;
    return true;
}

bool millerrabin(ull p) {
    if (p == 1) return false;
    int s = __builtin_ctzll(p - 1);
    ull d = p - 1 >> s;

    for (ull base: {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
        if (p == base) return true;
        if (p % base == 0) return false;
        if (comp(base, p, s, d)) return false;
    }
    return true;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        ull n; cin>> n;
        cout << (millerrabin(n)? "YES\n": "NO\n");
    }
}
