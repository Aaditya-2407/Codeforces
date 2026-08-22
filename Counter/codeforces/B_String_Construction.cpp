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
    int k;

   cin>>n;
   cin>>k;

   if(k>=n-1)
   {
    cout<<-1<<endl;
    return;

   }
   int count1 = (n + 1) / 2; 
    int count2 = n / 2;
    
    char char1 = '1';
    char char2 = '0';

    int target_blocks = n - k;
    int cheap_blocks = target_blocks - 2;
    
    string ans = "";
    int turn = 1; 

    for (int i = 0; i < cheap_blocks; i++)
    {
        if (turn == 1)
        {
            ans += char1;
            count1--;
            turn = 2; 
        }
        else
        {
            ans += char2;
            count2--;
            turn = 1; 
        }
    }

    if (turn == 1)
    {
        ans.append(count1, char1); 
        ans.append(count2, char2); 
    }
    else
    {
        ans.append(count2, char2); 
        ans.append(count1, char1); 
    }

    cout << ans << "\n";
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