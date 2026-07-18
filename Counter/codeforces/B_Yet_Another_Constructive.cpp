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
    int k;
    int m;

    cin >> n;
    cin>>k;
    cin>>m;

    if(k>m)
    {
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;

    for(int i = 1; i <= n; i++) 
    {
        if(i % k == 0)
        {
            cout << (m - k + 1) << " ";
        }
        else
        {
            cout << 1 << " ";
        }
    }
    cout << endl;
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