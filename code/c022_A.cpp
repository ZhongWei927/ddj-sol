#include <bits/stdc++.h>

using namespace std;

vector<string> g;

constexpr array<string_view, 11> keywords = {
    "DSAlCoda", "DCAlCoda", "DSAlFine", "DCAlFine", "Segno", "Coda", "ToCoda", "Fine", "1.", "2.", "]"
};

void solve(int l, int r, bool skip = false) {
    int ptr = l, L = -1;
    while (ptr < r) {
        if (g[ptr] == "||:") { L = ptr++; continue; }

        if (skip and (g[ptr] == "1." or g[ptr] == ":||")) {
            while (g[ptr] != ":||") ptr++;
            solve(ptr + 1, r, skip); break;
        }
        
        if (g[ptr] == ":||") { solve(L + 1, ptr++, true); continue; }
        
        if (find(keywords.begin(), keywords.end(), g[ptr]) != keywords.end()) { ptr++; continue; }

        cout << g[ptr++] << ' ';
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n; cin>>n;
    
    int SC = -1, SF = -1, CC = -1, CF = -1, S = -1, C = -1, TC = -1, F = -1;

    g.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> g[i];
        if (g[i] == "DSAlCoda") SC = i;
        if (g[i] == "DCAlCoda") CC = i;
        if (g[i] == "DSAlFine") SF = i;
        if (g[i] == "DCAlFine") CF = i;
        if (g[i] == "Segno") S = i;
        if (g[i] == "Coda") C = i;
        if (g[i] == "ToCoda") TC = i;
        if (g[i] == "Fine") F = i;
    }

    if (SC != -1) {
        solve(0, SC);
        solve(S + 1, TC, true);
        solve(C + 1, n, true);
    } else if (CC != -1) {
        solve(0, CC);
        solve(0, TC, true);
        solve(C + 1, n, true);
    } else if (SF != -1) {
        solve(0, SF);
        solve(S + 1, F, true);
    } else if (CF != -1) {
        solve(0, CF);
        solve(0, F, true);
    } else {
        solve(0, n);
    }
}