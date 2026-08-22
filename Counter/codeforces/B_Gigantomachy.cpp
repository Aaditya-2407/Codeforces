#include <iostream>
#include <vector>
#include <string>
#include <cctype>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    int a[n];
    int b[m];
    for(int i =0 ; i < n; i++)
    {
        cin>>a[i];
    }
    for(int i =0 ; i < m; i++)
    {
        cin>>b[i];
    }
    int h_a= a[0] + (n-1);
    int h_b = b[0] + (m-1);

    if(h_a>=h_b)
    {
        cout<<1<<endl;
        return;
    }
    else{
        cout<<2<<endl;
        return;
    }

    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t; 
    while (t--) {
        solve();
    }
    
    return 0;
}