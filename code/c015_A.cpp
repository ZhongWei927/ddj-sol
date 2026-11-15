#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
	int n; cin>>n;
	vector<int> p(n);
	for (auto&x:p) cin>>x;
	sort(p.begin(), p.end());
	cout<< accumulate(p.begin(), p.end(), 0LL, [&p, &n](long long res, long long x){ return res + abs(p[n/2] - x); }) <<'\n';
}