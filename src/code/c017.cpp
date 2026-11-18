#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, d; cin>>n>>m>>d;

    string title[1000];
    int month[1000], date[1000];

    for (int i=0;i<n;i++) {
        cin >> month[i] >> date[i];
        getline(cin, title[i]);
    }

    for (int i=0;i<n;i++) {
        for (int j=i+1;j<n;j++) {
            if (month[i] > month[j] or month[i] == month[j] and date[i] > date[j]) {
                swap(month[i], month[j]);
                swap(date[i], date[j]);
                swap(title[i], title[j]);
            }
        }
    }

    for (int i=0;i<n;i++) {
        if (month[i] > m or month[i] == m and date[i] >= d) {
            cout << month[i] << ' ' << date[i] << title[i] << endl;
        }
    }
    for (int i=0;i<n;i++) {
        if (month[i] < m or month[i] == m and date[i] < d) {
            cout << month[i] << ' ' << date[i] << title[i] << endl;
        }
    }
}