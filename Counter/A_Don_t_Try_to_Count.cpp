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
    int n, m;
    cin >> n >> m;
    
    string x, s;
    cin >> x >> s;
    
    
    int count = 0;
    for(int i = 0; i <= 5; i++)
    {
        if(x.find(s) != string::npos)
        {
            cout<<count<<endl;
            return;
        }
        x+=x;
        count++;
    }

    cout<<-1<<endl;
    
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