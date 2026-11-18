#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int q, last, serve = -1; cin>>q;

    vector<vector<int>> teams(2, vector<int>(6));
    for (int i=2;i>=0;i--)
        for (int j=0;j<=1;j++)
            cin >> teams[j][i] >> teams[j][5-i];

    vector<int> rotate(2);
    while (last = serve, q--)
        if (cin>>serve, serve != last and last != -1)
            rotate[serve]++;

    for (int j=0;j<=1;j++) {
        for (int i=0;i<3;i++)
            cout << teams[j][(6 - rotate[j] % 6 + i) % 6] << " \n"[i == 2];
        for (int i=5;i>=3;i--)
            cout << teams[j][(6 - rotate[j] % 6 + i) % 6] << " \n"[i == 3];
    }
}