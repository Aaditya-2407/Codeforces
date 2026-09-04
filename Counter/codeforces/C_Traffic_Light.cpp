#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <numeric>
using namespace std;

#define int long long
#define endl '\n'
#define f(i,n) for(int i=0;i<(n);i++)
#define rf(i,n) for(int i=(n)-1;i>=0;i--)
#define all(v) (v).begin(), (v).end()
#define srt(v) sort(all(v))
#define mxe(v) *max_element(all(v))
#define mne(v) *min_element(all(v))
#define pb push_back
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>
#define pll pair<long long,long long>

// Observations
/*

*/


void solve()
{
   
    int n;
    char c;
    cin >> n >> c;
    
    string s;
    cin >> s;
    
    
    if (c == 'g') {
        cout << 0 << "\n";
        return;
    }
    
    
    s += s;
    
    int max_wait = 0;
    int last_g_pos = -1;
    
    
    for (int i = s.length() - 1; i >= 0; i--) {
        if (s[i] == 'g') {
            last_g_pos = i; 
        }
        
        
        if (s[i] == c && i < n && last_g_pos != -1) {
            max_wait = max(max_wait, last_g_pos - i);
        }
    }
    
    cout << max_wait << "\n";
    return;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}