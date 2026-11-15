#include <bits/stdc++.h>

using namespace std;

constexpr const char* const ver[] = {
    "國文老師人美心善怎麼可以不交作業呢\n",
    "國文老師你的話讓我有點感動\n",
    "國文老師你的話真令人感動\n",
    "國文老師你的話真令人感動\n"
};

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n; cin>>n;
    long long tasks[100005];
    for (int i=0;i<n;i++) {
        cin >> tasks[i];
        if (i) tasks[i] += tasks[i-1];
    }
    long long record[3] = {}, progress = 0;
    for (int i=0;i<n;i++) {
        for (int j=0;j<5;j++) {
            int a; cin>>a; progress += a;
        }
        if (progress >= tasks[i]) record[i % 3] = 0;
        else record[i % 3] = 1;
        cout << ver[accumulate(record, record+3, 0)];
    }
}