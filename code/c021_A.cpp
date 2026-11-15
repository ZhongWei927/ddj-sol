#include <bits/stdc++.h>

using namespace std;

vector<string> g;

void solve(int l, int r, bool skip = false) {
    int ptr = l, L = -1;
    while (ptr != r) {
        if (g[ptr] == "||:") { L = ptr++; continue; }

        if (g[ptr] == ":||") {
            if (skip) break;
            solve(L + 1, ptr++, true); continue;
        }

        if (g[ptr] == "1.") {
            ptr++;
            if (skip) break;
            continue;
        }

        if (g[ptr] == "]" or g[ptr] == "2.") { ptr++; continue; }

        cout << g[ptr++] << ' ';
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n; cin>>n;
    g.resize(n); for (auto&x:g) cin>>x;
    solve(0, n);
}