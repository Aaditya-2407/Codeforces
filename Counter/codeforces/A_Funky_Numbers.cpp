#include <iostream>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long n;
    cin >> n;

    n = 8 * n + 2;

    for (long long a = 3; a * a < n; a += 2) {
        
        long long remaining = n - (a * a);
        long long b = round(sqrt(remaining)); 

        if (b * b == remaining && b >= 3) {
            cout << "YES" << endl;
            return 0;
        }
    }

    cout << "NO" << endl;
    return 0;
}