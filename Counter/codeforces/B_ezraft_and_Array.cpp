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
    cin >> n;

    vi p(n);
    int sum = 0;
    int mul = 1;
    for(int i =0; i < n; i++)
    {
        p[i] = i+1;
        sum = sum+p[i];

    }
    f(i,n){
        if(sum%p[i] != 0)
        {
            mul = mul*p[i];
        }
    }
    f(i,n)
    {
        p[i] = p[i]*mul;
    }

    f(i,n)
    {
        cout<<p[i]<<" ";
    }
    cout<<endl;

  
   
    
   
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