#include <iostream>

using namespace std;

int main() {
    int n; cin>>n;
    if (n % 400 == 0 or n % 100 != 0 and n % 4 == 0) cout<< "閏年" << endl;
    else cout << "平年" << endl;
}