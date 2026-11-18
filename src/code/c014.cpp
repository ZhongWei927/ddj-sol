#include <iostream>

using namespace std;

int main() {
    int n;
    cin>>n;

    long long tasks[100005], record[100005];

    for (int i=0;i<n;i++) {
        cin >> tasks[i];
    }

    long long progress = 0, homework = 0;
    for (int i=0;i<n;i++) {
        homework += tasks[i];
        for (int j=0;j<5;j++) {
            int a;
            cin>>a;
            progress += a;
        }

        if (progress >= homework) record[i] = 0;
        else record[i] = 1;

        int touched = 0;
        for (int j=i;j>=i-2;j--) {
            if (j >= 0) {
                touched += record[j];
            }
        }
        
        if (touched == 0) {
            cout << "國文老師人美心善怎麼可以不交作業呢" << endl;
        } else if (touched == 1) {
            cout << "國文老師你的話讓我有點感動" << endl;
        } else {
            cout << "國文老師你的話真令人感動" << endl;
        }
    }
}