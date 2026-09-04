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
    int n, x, y;
    cin >> n >> x >> y;
    
    vi num(n);
    int sum = 0;
    
    f(i, n)
    {
        cin >> num[i];
        sum += num[i];
    }

    srt(num);

    int count = 0;
    
    int left = sum - y;
    int right = sum - x;

    for(int i = 0; i < n - 1; i++) 
    {
       
        int min_needed = left - num[i];
        int max_needed = right - num[i];
        
        auto start_it = lower_bound(num.begin() + i + 1, num.end(), min_needed);
        
        auto end_it = upper_bound(num.begin() + i + 1, num.end(), max_needed);
        
        count += (end_it - start_it);
    }
    
    cout << count << endl;
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