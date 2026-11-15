#include <iostream>

using namespace std;

int main() {
    int n; cin>>n;
    for (int i=1;i<=n;i++) cout << string(i-1, 32) << string(n-i+1, 37) << '\n';
}