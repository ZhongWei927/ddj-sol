#include <iostream>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    
    int songs[100005], a[100005], new_songs[100005];
    for (int i = 1;i<=n;i++) {
        cin >> songs[i];
    }
    
    while (q--) {
        int f;
        cin>>f;
        
        for (int i=1;i<=n;i++) {
            cin >> a[i];
        }
        
        for (int i=1;i<=n;i++) {
            if (f == 1) {
                new_songs[i] = songs[a[i]];
            } else {
                new_songs[a[i]] = songs[i];
            }
        }

        
        for (int i=1;i<=n;i++) {
            songs[i] = new_songs[i];
        }
    }
    
    for (int i=1;i<=n;i++) {
        cout << songs[i] << ' ';
    }
} 