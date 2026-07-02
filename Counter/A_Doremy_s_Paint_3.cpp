#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <numeric>
#include <cmath> // For abs()
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
    vi a(n);
    f(i,n)
    {
        cin >> a[i];
    }
    
    srt(a);
    
    vi counts;
    int current_freq = 1;
    
    for(int i = 1; i < n; i++) {
        if(a[i] == a[i-1]) {
            current_freq++;
        } else {
            counts.pb(current_freq);
            current_freq = 1;
        }
    }
    counts.pb(current_freq); 
    
    if (counts.size() == 1) {
        cout << "Yes" << endl;
    } 
    else if (counts.size() == 2) {
        if (abs(counts[0] - counts[1]) <= 1) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    } 
    else {
        cout << "No" << endl;
    }
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