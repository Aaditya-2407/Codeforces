#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
using namespace std;

#define int long long
#define endl '\n'
#define f(i,n) for(int i=0;i<(n);i++)

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a;
    
    vector<pair<int, int>> ans(n);
    
    for (int i = 0; i < n; i++) {
        int health;
        cin >> health;

        int h = health % k;
        if (h == 0) {
            h = k;
        }
        
        ans[i] = {-h, i + 1};
    }

   
    sort(ans.begin(), ans.end());

    for (int i = 0; i < n; i++) {
        cout << ans[i].second << (i == n - 1 ? "" : " ");
    }
    cout << endl;
    return;
    

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (cin >> t) {
        while (t--) {
            solve(); 
        }
    }

    return 0;
}