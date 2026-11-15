#include <bits/stdc++.h>

using namespace std;

struct event {
    int month, date;
    string title;
};

int main() {
    int n, m, d; cin>>n>>m>>d;

    vector<event> g(n);
    for (auto&x:g) cin>>x.month>>x.date, cin.get(), getline(cin, x.title);

    sort(g.begin(), g.end(), [&m, &d](event&lhs, event&rhs){
        if ((lhs.month < m or lhs.month == m and lhs.date < d) == (rhs.month < m or rhs.month == m and rhs.date < d))
            return (lhs.month == rhs.month? lhs.date < rhs.date: lhs.month < rhs.month);
        else
            return (lhs.month < m or lhs.month == m and lhs.date < d? false: true);
    });
    for (auto&x:g) cout << x.month << ' ' << x.date << ' ' << x.title << '\n';
}