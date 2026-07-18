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
    
    cin>>n;
    int counter = 1;
    if(n == 1)
    {
        cout<<1<<endl;
        return;
    }

    for(int i = 2; i <= n; i++)
    {
        if(n%i!=0)
        {
            break;
        }
        else{
            counter++;
        }

    }
    cout<<counter<<endl;
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