#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, divisors = 0;
        cin >> n;
        for (int i=1;i<=n;i++) {
            if (n % i == 0) {
                divisors++;
            }
        }
        if (divisors == 2) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}