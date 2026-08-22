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
    
   
    vi a(3);
    f(i,3)
    {
        cin>>a[i];
       
    }
    int min_sum = INT_MAX;

    sort(a.begin(),a.end());
    f(i,2)
    {
        if(a[i] == a[i+1])
        {
            cout<<0<<endl;
            return;
        }
        if(a[i]!=a[i+1])
        {
            min_sum = min(min_sum, (a[i+1]-a[i]));
        }
        
    }
    cout<<min_sum<<endl;
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