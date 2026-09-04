#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

#define int long long
#define endl '\n'
#define f(i,n) for(int i=0;i<(n);i++)
#define rf(i,n) for(int i=(n)-1;i>=0;i--)
#define all(v) (v).begin(), (v).end()
#define srt(v) sort(all(v))
#define mxe(v) *max_element(all(v))
#define mne(v) *min_element(all(v))
#define pb push_back
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>
#define pll pair<long long,long long>

// Observations
/*
 
*/

void solve()
{
    int n;
    int k;
    cin >> n;
    cin >> k;
    vi nums(n);
    f(i,n)
    {
        cin >> nums[i];
    }

    srt(nums);

    int left = 0;
    int right = n - 1;
    int point = 0;

    while(left < right)
    {
        int sum = nums[left] + nums[right];
        if(sum < k)
        {
            left++;
        }
        else if(sum > k)
        {
            right--;
        }
        else {
            point++;
            left++;
            right--;
        }
    }
    cout << point << endl;
    return;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}