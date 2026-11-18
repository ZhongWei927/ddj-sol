#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin>>s;

    int curr = 0, res = 1;
    
    for (int i=1;i<s.size();i++) {
        if (s[i] != s[i-1]) {
            curr = 0;
        }
        res = max(res, ++curr);
    }
}