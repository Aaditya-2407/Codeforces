#include <iostream>
#include <string>
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
    int n;
    cin >> n;
    string s;
    cin >> s;
    

    
    int ans = 0; 
    int ch = 0;
    f(i,n)
    {
        if(s[i] != s[i-1])
        {
            ch++;
        }
    }
    if(ch==2)
    {
        cout<<2<<endl;
        return;
    }
    else{
        cout<<1<<endl;
        return;
    }
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