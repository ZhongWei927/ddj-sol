#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int inContention = n;
    string drivers[1000];
    double laps[1000][100], finish[1000], leader = 1e9;
    int lapsToGo[1000];
    bool dnf[1000] = {};

    for (int i=0;i<n;i++) {
        cin >> drivers[i];
        double temp = 0;

        for (int j=0;j<m;j++) {
            cin >> laps[i][j];
            temp += laps[i][j];
            if (laps[i][j] == -1) {
                inContention--;
                dnf[i] = true;
                break;
            }
        }

        if (dnf[i]) {
            continue;
        }

        leader = min(leader, temp);
    } 

    for (int i=0;i<n;i++) {
        if (dnf[i]) {
            lapsToGo[i] = m + 1;
            continue;
        }
        double curr = 0;
        for (int j=0;j<m;j++) {
            curr += laps[i][j];
            if (curr >= leader) {
                finish[i] = curr;
                lapsToGo[i] = m - j - 1;
                break;
            }
        }
    }

    for (int i=0;i<n;i++) {
        for (int j=i+1;j<n;j++) {
            if (lapsToGo[i] > lapsToGo[j] or lapsToGo[i] == lapsToGo[j] and finish[i] > finish[j]) {
                swap(finish[i], finish[j]);
                swap(lapsToGo[i], lapsToGo[j]);
                swap(drivers[i], drivers[j]);
            }
        }
    }

    string s;
    cin >> s;

    cout << fixed << setprecision(3);
    int leaderLaps = 0;
    double leaderTime = leader;
    for (int i=0;i<inContention;i++) {
        if (i == 0) {
            cout << drivers[i] << ' ' << finish[i] << endl;
        } else {
            if (leaderLaps == lapsToGo[i]) {
                cout << drivers[i] << " +" << finish[i] - leaderTime << endl;
            } else {
                cout << drivers[i] << " +" << lapsToGo[i] - leaderLaps << " Lap";
                if (lapsToGo[i] - leaderLaps > 1) cout << "s";
                cout << endl;
            }

            if (s == "Interval") {
                leaderTime = finish[i];
                leaderLaps = lapsToGo[i];
            }
        }
    }
}