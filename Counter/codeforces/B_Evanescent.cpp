#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
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
    cin >> n;
    string s;
    cin >> s;
    
    
    int start = 1;
    for (int i = 1; i < n; i++) {
        if (s[i] != s[i-1]) {
            start++;
        }
    }
    
    int mini = start;
    
    for (int i = 1; i < n - 1; i++) {
        int before = (s[i-1] != s[i]) + (s[i] != s[i+1]);
        int after= (s[i-1] != s[i+1]);
        
        int change = after - before;
        mini = min(mini, start + change);
    }
    
    cout << mini << "\n";
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