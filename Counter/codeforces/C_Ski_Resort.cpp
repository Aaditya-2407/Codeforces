#include <iostream>
#include <vector>

using namespace std;

// Using long long for everything to avoid overflow issues, 
// since the answer can be large (up to n*(n+1)/2 ways)
#define int long long
#define endl '\n'

void solve() {
    int n, k, q;
    cin >> n >> k >> q;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int total_ways = 0;
    
   int streak = 0;
   for(int i =0; i < n; i++)
   {
    if(a[i] <= q)
    {
        streak++;
    }
    else{
        if(streak >= k)
        {
            int N = streak - k +1;
            total_ways += (N*(N+1)/2);
            streak = 0;
        }
        else{
            streak = 0;
        }
    }

   }
   if(streak >= k)
        {
            int N = streak - k +1;
            total_ways += (N*(N+1)/2);
            streak = 0;
        }
    

    cout << total_ways << endl;
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