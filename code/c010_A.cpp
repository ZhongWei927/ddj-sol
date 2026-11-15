#include <iostream>

using namespace std;

int main() {
    int n; cin>>n;

    int streak = 0, fava = 0, res = 0;
    while (n-- && ++res) {
        int a; cin>>a;
        if (a) streak = 0;
        else if (++fava and ++streak == 4) break;
    }
    cout << fava << ' ' << res << '\n';
}