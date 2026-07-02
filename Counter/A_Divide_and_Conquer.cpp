#include <iostream>
using namespace std;

#define int long long
#define endl '\n'

void solve()
{
    int x, y;
    cin >> x >> y;
    if(x==y)
    {
        cout<<"YES"<<endl;
        return;
    }
    else if(x%y==0)
    {
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
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