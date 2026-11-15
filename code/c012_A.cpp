#include <iostream>

using namespace std;

int main() {
    int n; cin>>n;
    int jimmy = 0, wei = 0;
    char a, b;
    while (cin >> a >> b) {
        if (a == b) continue;
        if (a == 'r' and b == 's' or a == 's' and b == 'p' or a == 'p' and b == 'r') jimmy++;
        else wei++;
        
        if (max(wei, jimmy) >= n and abs(wei-jimmy) >= 2) break;
    }
    cout << jimmy << ' ' << wei << '\n';
}