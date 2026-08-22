#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    vector<int> freq(60, 0); 
    int maxfreq = 0;
    
    for(int i = 0; i < n; i++) {
        int h;
        cin >> h;
        freq[h]++;
        if(freq[h] > maxfreq) {
            maxfreq = freq[h];
        }
    }
    
    cout << n - maxfreq << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while(t--) {
        solve();
    }
    
    return 0;
}