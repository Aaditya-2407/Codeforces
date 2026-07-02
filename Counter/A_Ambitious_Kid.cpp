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
    if (!(cin >> n)) return;
    
    int minu = INT_MAX;
    
    f(i, n)
    {
        int temp;
        cin >> temp;
        if (temp == 0) {
            cout << 0 << endl;
            return;
        } else {
            minu = min(minu, abs(temp));
        }
    }
    cout << minu << endl;
    return;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve(); 

    return 0;
}