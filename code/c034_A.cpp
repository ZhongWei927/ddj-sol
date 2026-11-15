#include <bits/stdc++.h>
 
using namespace std;

int main() {
    set<int> s;
    int n, k, base; cin>>n>>k;
    
    vector<int> h(n);
    for (auto&x:h) cin>>x;
    base = h[k-1];
    
    for (int i=0;i<n;i++)
        if (h[i]>=base) s.insert(h[i]);
    
    for (auto it = next(s.begin()); it != s.end(); it++) {
        if (*it - base > *prev(it)) {
        	cout << "NO" << endl;
        	return 0;
		}
    }
    cout<<"YES\n";
}