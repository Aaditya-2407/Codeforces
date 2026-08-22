#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <utility>
#include <cmath> 
using namespace std;

#define int long long
#define endl '\n'
#define f(i,n) for(int i=0;i<(n);i++)

void solve()
{
    int n;
    cin >> n;
    
    vector<int> a(n);
    vector<int> b(n);
    vector<int> c(n);

    f(i,n)
    {
        cin>>a[i];
    }
    f(i,n)
    {
        cin>>b[i];
    }
    f(i,n)
    {
        cin>>c[i];
    }
    int place = n-1;
    int sum = 0;

    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    sort(c.begin(),c.end());

    while (place > -1)
    {
        
    }
 
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