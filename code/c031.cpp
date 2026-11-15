#include <iostream>

using namespace std;

int votes[100005];

int main() {
    long long n, m, res, v = 0;
    cin>>n>>m;
    for (int i=0;i<m;i++) {
        int a;
        cin>>a;
        if (++votes[a] > v) {
            v = votes[a], res = a;
        }
    }
    cout << res << '\n';
}