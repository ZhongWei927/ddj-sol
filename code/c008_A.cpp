#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m; cin>>n>>m;
    while (m) tie(n, m) = make_tuple(m, n % m);
    cout << vector<string>{"NO", "YES"}[n == 1] << '\n';
}