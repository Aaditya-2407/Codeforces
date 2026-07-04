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
    
    vector<int> b(n);
    f(i, n)
    {
        cin >> b[i];
    }
    
    vector<int> a;
    a.push_back(b[0]);
    for(int i =1; i < n; i++)
    {
        if(b[i-1] <= b[i])
        {
            a.push_back(b[i]);
        }
        else
        {
            a.push_back(b[i]);
            a.push_back(b[i]);
        }
    }
    cout<<a.size()<<endl;
    for(int i = 0; i < a.size(); i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
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