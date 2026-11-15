#include <iostream>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    
    int *before = new int[100005], *after = new int[100005];

    for (int i = 1;i<=n;i++) {
        cin >> before[i];
    }

    while (q--) {
        int f;
        cin>>f;
        
        for (int i=1;i<=n;i++) {
            int a; cin >> a;
            if (f == 1) {
                after[i] = before[a];
            } else {
                after[a] = before[i];
            }
        }
        swap(before, after);
    }
    
    for (int i=1;i<=n;i++) {
        cout << before[i] << ' ';
    }
} 