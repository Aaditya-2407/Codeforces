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
    int k;
    int n;
    cin >> n;
    cin>>k;

    vi a(n);
    f(i,n) cin >> a[i];

    //i need maximum distance between 2 feul pumps.
    int diff = 0;
    for(int i = 0; i < a.size()-1;i++)
    {
        diff = max(diff,a[i+1]-a[i]);
    }
    diff=max(diff,(k-a[a.size()-1]+k-a[a.size()-1]));
    diff=max(diff,a[0]-0);
    

    cout<<diff<<endl;

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