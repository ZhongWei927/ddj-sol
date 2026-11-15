#include <bits/stdc++.h>

using namespace std;

struct d {
    int lapsToGo;
    double t;
    string name;
};

bool operator < (d& lhs, d& rhs) {
    if (lhs.lapsToGo == rhs.lapsToGo) return lhs.t < rhs.t;
    else return lhs.lapsToGo < rhs.lapsToGo;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int n, m; cin >> n >> m;

    unordered_map<string, vector<double>> dt;
    double leader = 1e9;
    for (int i=0;i<n;i++) {
        string tag; cin>>tag;

        vector<double> laps;
        for (int j=0;j<m;j++) {
            double t; cin>>t;
            if (abs(t + 1) < 1e-7) break;
            else {
                laps.push_back(t);
                if (j) laps[j] += laps[j-1];
            }
        }
        
        if (laps.size() == m) {
            leader = min(leader, laps.back());
            dt[tag] = {};
            dt[tag].swap(laps);
        }
    }
    
    vector<d> res;
    for (auto&[tag, laps]:dt) {
        auto it = lower_bound(laps.begin(), laps.end(), leader);
        res.push_back(d{(int)(laps.end() - it) - 1, *it, tag});
    }
    sort(res.begin(), res.end());

    string s; cin>>s; cout << fixed << setprecision(3);

    auto cmp = res.front();
    for (auto&x:res) {
        if (x.lapsToGo == 0 and x.t == leader)
            cout << x.name << " " << x.t << '\n';
        else {
            int gap = x.lapsToGo - cmp.lapsToGo;
            if (gap == 0)
                cout << x.name << " +" << x.t - cmp.t << '\n';
            else
                cout << x.name << " +" << gap << (gap == 1? " Lap\n": " Laps\n");
            if (s == "Interval") swap(x, cmp);
        }
    }
}