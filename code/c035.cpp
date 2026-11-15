#include <iostream>
 
using namespace std;

int main() {    
    int n, k;
    cin>>n>>k;

    while (n--) {
        string s;
        cin>>s;
        
        for (int i=0;i<s.size();i++) {
            if (isupper(s[i])) cout << (char)((s[i] - 'A' + 26 - k) % 26 + 'A');
            else if (islower(s[i])) cout << (char)((s[i] - 'a' + 26 - k) % 26 + 'a');
            else cout << s[i];
        }
        cout << ' ';
    }
}