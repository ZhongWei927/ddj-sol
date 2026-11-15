#include <iostream>
#include <algorithm>
 
using namespace std;

int main() {
    int n, k, base;
    cin>>n>>k;
    
    int h[100005];
    for (int i=0;i<n;i++) {
        cin >> h[i];
    }
    base = h[k-1];
    
    sort(h, h + 5);
    
    int i = 0;
    while (h[i] < base) {
        i++;
    }
    
    for (; i < n; i++) {
        if (h[i] - base > h[i-1]) {
        	cout << "NO" << endl;
        	return 0;
		}
    }
    cout<<"YES\n";
}