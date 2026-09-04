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
    string p, s;
    cin >> p >> s;
    
    int i = 0;
    int j = 0;
    int n = p.size();
    int m = s.size();

    while (i < n && j < m) 
    {
        if (p[i] != s[j]) {
            cout << "NO" << endl;
            return;
        }

        char current_char = p[i];
        int count_p = 0;
        int count_s = 0;

        while (i < n && p[i] == current_char) {
            count_p++;
            i++;
        }

        while (j < m && s[j] == current_char) {
            count_s++;
            j++;
        }

        if (count_s < count_p || count_s > 2 * count_p) {
            cout << "NO" << endl;
            return;
        }
    }

    if (i == n && j == m) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
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