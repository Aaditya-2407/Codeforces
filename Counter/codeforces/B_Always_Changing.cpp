#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int B0 = 0, B1 = 0;
    for (char c : s) {
        if (c == '0') B0++;
        else B1++;
    }

    int diff_B = B0 - B1;

    if (abs(diff_B) > 2) {
        cout << -1 << "\n";
        return;
    }

    string A = "";
    A += s[0];
    for (int i = 1; i < n; i++) {
        if (s[i] != A.back()) {
            A += s[i];
        }
    }

    int first0 = -1, last0 = -1;
    int first1 = -1, last1 = -1;

    for (int i = 0; i < A.length(); i++) {
        if (A[i] == '0') {
            if (first0 == -1) first0 = i;
            last0 = i;
        } else {
            if (first1 == -1) first1 = i;
            last1 = i;
        }
    }

    int max_k = -1;

    for (int type = 0; type < 4; type++) {
        int L = -1, R = -1;
        int delta_K = 0;

        if (type == 0) { 
            L = first0; R = last0;
            delta_K = 1;
        } else if (type == 1) { 
            L = first1; R = last1;
            delta_K = -1;
        } else if (type == 2) { 
            L = first0; R = last1;
            delta_K = 0;
        } else if (type == 3) {
            L = first1; R = last0;
            delta_K = 0;
        }

        if (L != -1 && R != -1 && L <= R) {
            int k = R - L + 1;
            
            if (abs(delta_B - delta_K) <= 1) {
                max_k = max(max_k, k);
            }
        }
    }

    if (max_k == -1) {
        cout << -1 << "\n";
    } else {
        cout << n - max_k << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}