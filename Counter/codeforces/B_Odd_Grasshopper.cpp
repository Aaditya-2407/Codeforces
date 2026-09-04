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
    long long x,n;
    cin>>x>>n;
    long long d = 0;
    long long remainder= n%4;
    if(remainder==0)
    {
        d=0;
    }
    else if(remainder==1)
    {
        d=-n;
    }
    else if(remainder==2)
    {
        d=1;
    }
    else if(remainder==3)
    {
        d=n+1;
    }
    if (x % 2 == 0) {
        cout << x + d << "\n";
        
    } else {
        cout << x - d << "\n";
    }
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