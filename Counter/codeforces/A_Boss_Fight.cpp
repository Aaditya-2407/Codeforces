#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    
    map<int, int> freq;
    int total_sum = 0;
    int max_freq = 0;
    int max_val = 0;
    
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        freq[x]++;
        total_sum += x;
        
        if (freq[x] > max_freq) {
            max_freq = freq[x];
            max_val = x;
        }
    }
    
    int others = n - max_freq;
    int max_allowed_copies = others + 2;
    
    if (max_freq > max_allowed_copies) {
        int wasted_copies = max_freq - max_allowed_copies;
        total_sum -= (wasted_copies * max_val);
    }
    
    cout << total_sum << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}