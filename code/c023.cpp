#include <iostream>

using namespace std;

int main() {
    int n; cin>>n;
    
    int a[100005];
    for (int i=0;i<n;i++) {
        cin >> a[i];
    }

    int curr = 0, res = 1;
    for (int i=1;i<=2*n;i++) {
        if (a[i%n] > a[(i-1)%n]) curr++;
        else {
            res = max(res, curr);
            curr = 1;
        }
    }
    cout << res << endl;
}