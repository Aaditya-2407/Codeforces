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
    f(i, n)
    {
        cin >> a[i];
    }
    vector<int> b;
    vector<int> c;
    sort(a.begin(), a.end());
    if(a[0] == a[n-1])
    {
        cout<<-1<<endl;
        return;
    }
    int max_val = a[n-1];

    f(i,n)
    {
        if(a[i] != max_val)
        {
            b.push_back(a[i]);
        }
        else
        {
            c.push_back(a[i]);
        }
    }
    cout<<b.size()<<" ";
    cout<<c.size()<<endl;
    f(i,b.size())
    {
        cout<<b[i]<<" ";
    }
    cout<<endl;
    f(i,c.size())
    {  
        cout<<c[i]<<" ";
    }
    cout<<endl;
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