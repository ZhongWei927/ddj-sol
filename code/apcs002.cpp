#include <iostream>

using namespace std;

int main() {
    long long n, w1, w2, h1, h2;
    cin>>n>>w1>>w2>>h1>>h2;

    long long res = 0, curr = 0, v1 = w1*w1*h1, v2 = w2*w2*h2;
    while (n--) {
        long long v; cin>>v;
        if (curr >= v1) res = max(res, (min(v1+v2, curr+v)-curr)/(w2*w2));
        else res = max(res, max(min(curr+v, v1+v2)-v1, 0LL)/(w2*w2) + (min(v1, curr+v)-curr)/(w1*w1));
        curr = min(v1+v2, curr+v);
    }

    cout << res << endl;
}