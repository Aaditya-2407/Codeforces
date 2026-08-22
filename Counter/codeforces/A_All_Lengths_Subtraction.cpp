#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    bool forward = true, backward = true;

    for (int i = 0; i < n; i++) {
        if (p[(i + 1) % n] != (p[i] % n) + 1) {
            forward = false;
        }
        if (p[i] != (p[(i + 1) % n] % n) + 1) {
            backward = false;
        }
    }

    if (forward || backward) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}