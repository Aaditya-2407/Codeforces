#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
using namespace std;

#define int long long
#define endl '\n'
#define f(i,n) for(int i=0;i<(n);i++)

void solve()
{
    int x;
    cin >> x;
    
    int i = 2;
    while(true)
    {
        int count = 0;
        string ans = to_string(abs(x*i));
        for(int j = 0; j < ans.length()-1; j++)
        {
            if(ans[j] != ans[j+1])
            {
                count++;
            }
            if(count > 2)
            {
                break;
            }
        }
        if(count <= 2)
        {
            cout << i <<endl;
            return;
        }
        i++;
        

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