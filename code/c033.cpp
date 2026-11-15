#include <iostream>

using namespace std;

int main() {
    int a[26] = {};
    string s;
    cin>>s;
    
    for (int i=0;i<s.size();i++) {
        a[s[i]-'A']++;
    }
    
    bool possible = true;
    char middle;
    for (int i=0;i<26;i++) {
        if (a[i] % 2 == 1) {
            if (possible) {
                possible = false;
                middle = 'A' + i;
            } else {
                cout << "NO SOLUTION" << endl;
                return 0;
            }
        }
    }
    for (int i=0;i<26;i++) {
        char c = 'A' + i;
        for (int j=0;j<a[i]/2;j++) {
            cout << c;
        }
    }
    if (!possible) {
        cout << middle;
    }
    for (int i=25;i>=0;i--) {
        char c = 'A' + i;
        for (int j=0;j<a[i]/2;j++) {
            cout << c;
        }
    }
}