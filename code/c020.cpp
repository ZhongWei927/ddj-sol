#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, q; 
    cin >> n >> q;

    int songs[100005];
    for (int i = 0; i < n; ++i) {
        cin >> songs[i];
    }

    int last_op, curr_id = 0, elapsed = 1, playing = 1; 
    cin >> last_op;

    int op[100005];
    for (int i = 0; i < q - 1; ++i) {
        cin >> op[i];
    }
    op[q - 1] = 0;

    for (int i = 0; i < q; ++i) {
        int x = op[i];
        
        if (playing && ++elapsed > songs[curr_id]) {
            elapsed = 1;
            curr_id = (curr_id + 1) % n;
        }

        if (x) {
            last_op++;
        } else {
            if (last_op == 1) {
                playing ^= 1;
            } else if (last_op == 2) {
                playing = 1; 
                elapsed = 1; 
                curr_id = (curr_id + 1) % n;
            } else if (last_op == 3) {
                playing = 1; 
                elapsed = 1; 
                curr_id = (curr_id + n - 1) % n;
            }
            last_op = 0;
        }
    }

    cout << curr_id + 1 << '\n';
}