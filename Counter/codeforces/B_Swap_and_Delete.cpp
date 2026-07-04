#include <iostream>
#include <string>
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
    string s;
    cin >> s;
    
    int count0 = 0;
    int count1 = 0;
    
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '0') count0++;
        else count1++;
    }
    
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '1') {
            // We need a '0'
            if (count0 > 0) {
                count0--;
            } else {
                break;
            }
        } 
        else if (s[i] == '0') {
            // We need a '1'
            if (count1 > 0) {
                count1--;
            } else {
                break; 
            }
        }
    }
    
    cout << count0 + count1 << endl;
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