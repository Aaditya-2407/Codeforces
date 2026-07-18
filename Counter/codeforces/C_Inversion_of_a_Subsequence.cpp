#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    vector<int> a(n), b(n);
    int total_a_ones = 0;
    int total_b_zeros = 0;
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == 1) total_a_ones++;
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        if (b[i] == 0) total_b_zeros++;
    }
    
    int ones_to_zeros = 0;
    int zeros_to_ones = 0;
    
    for (int i = 0; i < n; i++) {
        if (a[i] == 1 && b[i] == 0) ones_to_zeros++;
        if (a[i] == 0 && b[i] == 1) zeros_to_ones++;
    }
    
    if (ones_to_zeros == 0 && zeros_to_ones == 0) {
        cout << 0 << "\n";
        return;
    }
    
    if (ones_to_zeros % 2 == 1) {
        cout << 1 << "\n";
        return;
    }
    
    if (ones_to_zeros > 0 && ones_to_zeros % 2 == 0) {
        cout << 2 << "\n";
        return;
    }
    

    if (total_a_ones == 0 || total_b_zeros == 0) {
        cout << -1 << "\n";
    } else {
        cout << 2 << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}