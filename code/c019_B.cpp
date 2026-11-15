#include <bits/stdc++.h>

using namespace std;

int main() {    
    int n, q; cin>>n>>q;
    vector<int> songs(n); for (auto&x:songs) cin>>x;
    while (q--) {
        int op; vector<int> new_songs(n), a(n);
        cin >> op; for (auto&x:a) cin>>x;
        for (int i=0;i<n;i++) {
            if (op == 1) new_songs[i] = songs[a[i]-1];
            else new_songs[a[i]-1] = songs[i];
        }
        songs.swap(new_songs);
    }
    for (auto&x:songs) cout << x << " \n"[&x == &songs.back()];
}