#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin>>n;

	int p[200005];
	for (int i=0;i<n;i++) {
		cin >> p[i];
	}
	sort(p, p + n);

	long long res = 0;
	for (int i=0;i<n;i++) {
		res += abs(p[i] - p[n/2]);
	}
	
	cout << res << '\n';
}