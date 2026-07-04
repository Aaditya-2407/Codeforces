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
    cin>>n;
    
    
    vector<int> a(n);
    f(i, n)
    {
        cin >> a[i];
    }
    int even =0, odd =0;
    f(i,n)
    {
        if(a[i]%2 == 0)
        {
            even++;
        }
        else
        {
            odd++;
        }
    }

    if(odd == 2 && even == 0)
    {
        cout<<"YES"<<endl;
        return;

    }
    else if(odd == 0)
    {
        cout<<"YES"<<endl;
        return;
    }
    else if(odd%2 == 0 && even!=0)
    {
        cout<<"YES"<<endl;
        return;

    }
    else if(odd%2 != 0 && even!=0)
    {
        cout<<"NO"<<endl;
        return;
    }
    else if(odd%2 == 0 && even==0)
    {
        cout<<"NO"<<endl;
        return;
    }
    else if(odd%2 != 0 && even==0)
    {
        cout<<"YES"<<endl;
        return;
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