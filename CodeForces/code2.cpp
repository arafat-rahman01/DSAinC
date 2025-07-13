#include <iostream>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        int balance = 0;
        bool canBreak = false;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') balance++;
            else balance--;

            if (balance == 0 && i != s.size() - 1) {
                canBreak = true;
                break;
            }
        }

        if (canBreak) cout << "YES\n";
        else cout << "NO\n";
    }
}
