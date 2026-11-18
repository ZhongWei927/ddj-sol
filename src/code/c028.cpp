#include <iostream>

using namespace std;

int main() {
    int n;
    cin>>n;
    int a[100005], b[100005];
    for (int i=0;i<n;i++) {
        cin >> a[i];
    }
    for (int i=0;i<n;i++) {
        cin >> b[i];
    }
    int me = 0, bus = 0;

    for (int i=0;i<n;i++) {
        int t, p, q;
        cin>>t>>p>>q;

        me += a[i];
        bus += b[i];

        if (p < q and !(p <= bus % t and bus % t < q) or
            p > q and (q <= bus % t and bus % t < p))
            bus = (bus - p - 1 + t) / t * t + p;
        if (bus > me) {
            cout << "YES" << endl;
            return 0;
        }
        if (p < q and !(p <= me % t and me % t < q) or
            p > q and (q <= me % t and me % t < p))
            me = (me - p - 1 + t) / t * t + p;
    }
    cout << "NO" << endl;
}