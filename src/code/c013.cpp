#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    long long n, m, k; cin>>n>>m>>k;

    long long a = n, b = m, x = 1, y = 0, x1 = 0, y1 = -1;
    while (b) {
        tie(x, x1) = make_tuple(x1, x - a / b * x1);
        tie(y, y1) = make_tuple(y1, y - a / b * y1);
        tie(a, b) = make_tuple(b, a % b);
    }
    tie(x, y) = make_tuple(x * k / a, y * k / a);
    tie(n, m) = make_tuple(n / a, m / a);

    long long q = min(x / m, y / n) - (min(x, y) < 0);
    cout << x - q * m << ' ' << y - q * n << '\n';
}