#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Fast I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    if (!(cin >> n)) return 0;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
   
    int max_days = min(a[0], a[n - 1]);
    
    for (int i = 0; i < n - 1; i++) {
        int pair_broken_day = max(a[i], a[i + 1]);
        
        max_days = min(max_days, pair_broken_day);
    }
    
    cout << max_days << "\n";
    return 0;
}