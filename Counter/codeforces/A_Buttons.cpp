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
    int n = 3;
    
    
    vector<int> a(n);
    f(i, n)
    {
        cin >> a[i];
    }
    if(a[0] == a[1] && a[2]%2 == 0)
    {
        cout<<"Second"<<endl;
    }
    else if(a[0] == a[1] && a[2]%2 !=0)
    {
        cout<<"First"<<endl;
    }
    else if(a[0] > a[1])
    {
        cout<<"First"<<endl;
    }
    else if(a[0] < a[1])
    {
        cout<<"Second"<<endl;
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