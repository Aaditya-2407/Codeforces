#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#define vi vector<int>
#define f(i,n) for(int i=0;i<(n);i++)


using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    vi a(n);
    vi b(n);
    vi c(2*n);

    
    
    f(i,n){
        cin>>a[i];
        c[i] = a[i];
        


    }
    f(i,n){
        cin>>b[i];
        c[n+i]=b[i];
    }

    int ans = 1; 
    int counter = 1;
    sort(c.begin(),c.end());
    for(int i = 0; i < n;i++)
    {
        
        
        if(a[i] != a[i+1])
        {
            
            ans = max(ans, counter);
            
        }
        else {
            counter++;
        }
    }
    cout<<ans<<endl;
    return;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}