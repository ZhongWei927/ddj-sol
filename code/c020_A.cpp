#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, q; cin>>n>>q;
    vector<int> songs(n);
    for (auto&x:songs) cin>>x;

    int last_op, curr_id = 0, elapsed = 1, playing = 1; cin>>last_op;

    vector<int> op(q - 1); 
    for (auto&x:op) cin>>x; op.push_back(0);

    for (auto&x:op) {
        if (playing and ++elapsed > songs[curr_id])
            elapsed = 1, curr_id = (curr_id + 1) % n;

        if (x) last_op++;
        else {
            if (last_op == 1) playing ^= 1;
            else if (last_op == 2) playing = 1, elapsed = 1, curr_id = (curr_id + 1) % n;
            else if (last_op == 3) playing = 1, elapsed = 1, curr_id = (curr_id + n - 1) % n;
            last_op = 0;
        }
    }

    cout << curr_id + 1 << '\n';
}