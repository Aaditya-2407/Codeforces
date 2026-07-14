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

    vi p(n);

    int odd = 1;
    int even = 0;

    for(int i = 1; i <= n+1; i++)
    {
        if(i%2 == 0)
        {
            p[odd] = i;
            odd+=2;
        }
        else{
            p[even] = i;
            even+=2;
        }
    }
    for (int i = 0; i<n; i+=2)
    {
        swap(p[i],p[i+1]);
    }


    f(i,n){
        cout<<p[i]<<" ";
    }
    cout<<endl;
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