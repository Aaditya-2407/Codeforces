#include <iostream>
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
    int n, k;
    cin >> n >> k;
    
    vector<int> a(n);
    f(i, n)
    {
        cin >> a[i];
    }
    
    int mini = INT_MAX;
    
    
    f(i, n)
    {
        for(int j = 0; j < k; j++)
        {
            if((a[i] + j) % k == 0)
            {
                mini = min(mini, j);
            }
        }
    }
    
    
    if(k == 4)
    {
        int count = 0;
        f(i, n)
        {
            if(a[i] % 2 == 0)
            {
                count++;
            }
        }
        
        int special_cost = 0;
        if(count >= 2) {
            special_cost = 0; 
        }
        else if(count == 1) {
            special_cost = 1; 
        }
        else {
            special_cost = 2; 
        }
        
        
        mini = min(mini, special_cost);
    }
    
    
    cout << mini << endl;
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