#include <iostream>

using namespace std;

int main() {
    int good = 0, fava = 0, n, h;
    cin>>n>>h;

    int res = 0, breakdown = 0, limit = 0;
    bool penalty = false;
    while (n--) {
        if (h == 0) break;

        int a;
        cin>>a;

        if (limit) {
            limit--;
            continue;
        }

        if (penalty and !a) {
            h--;
            if (h == 1) {
                limit = 4;
                breakdown++;
                fava = 0;
                penalty = false;
            }
            continue;
        }
        penalty = false;

        if (a) {
            good++;
            fava = 0;
        } else {
            fava++;
            good = 0;
            res++;
        }

        if (fava == 4) {
            penalty = true;
        }
        if (good == 3) {
            good = 0;
            h++;
        }
    }
    cout << breakdown << ' ' << res << '\n';
}