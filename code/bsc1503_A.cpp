#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        if (n == 1) {
            cout << "NO" << endl;
            continue;
        }

        bool isprime = true;
        for (int i=2;i*i<=n;i++) {
            if (n % i == 0) {
                cout << "NO" << endl;
                isprime = false;
                break;
            }
        }

        if (isprime) {
            cout << "YES" << endl;
        }
    }
}