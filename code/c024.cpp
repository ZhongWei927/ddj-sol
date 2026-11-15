#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    int types[n + 5];
    int streaks[n + 5];
    int m = 0;

    int res1 = 0, res2 = 0, res3 = 0, res4 = 0;

    for (int i = 0, type = -1, streak = 0; i <= n; i++) {
        int k = type ^ 1;
        if (i < n) cin >> k;

        if (k != type) {
            if (streak) {
                types[m] = type;
                streaks[m] = streak;
                m++;
                if (!k) res1 += streak / 2;
            }
            streak = 0;
        }
        type = k; streak++;
    }

    int quota = (types[0] and !(streaks[0] % 2));
    for (int i = 0; i < m; i++) {
        int ends = (i == 0) + (i == m - 1);

        if (!types[i]) {
            res2 += (streaks[i] - 1 + ends) / 2;
            res3 += (streaks[i] + ends) / 3;
        } else if (i != 0) {
            bool oneleft = (i - 1 == 0 and streaks[i - 1] % 2 == 1) or
                (i - 1 != 0 and streaks[i - 1] % 2 == 0);

            if (quota == 1 and oneleft) {
                res4++; quota = streaks[i] % 2 == 0;
            } else {
                quota += streaks[i] % 2 == 0;
                if (quota == 2 or (quota == 1 and oneleft)) {
                    res4++; quota = 0;
                } else {
                    quota = streaks[i] % 2 == 0;
                }
            }
        }
    }
    if (types[m - 1] == 0 and streaks[m - 1] % 2 == 1 and quota == 1)
        res4++;

    cout << res1 << ' ' << res2 << ' ' << res3 << ' ' << res2 + res4 << '\n';
}