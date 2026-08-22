#include <iostream>
#include <vector>
#include <string>
#include <cctype>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;


    vector<bool> has_letter(26, false);

    for (int i = 0; i < n; ++i) {
        string word;
        cin >> word;
        has_letter[toupper(word[0]) - 'A'] = true;
    }

    vector<string> abbreviations(m);
    for (int i = 0; i < m; ++i) {
        cin >> abbreviations[i];
    }

    vector<bool> is_built(m, false);
    
    bool made_progress = true;
    while (made_progress) {
        made_progress = false; 
        
        for (int i = 0; i < m; ++i) {
            if (!is_built[i]) {
                bool can_build = true;
                
                for (char c : abbreviations[i]) {
                    if (!has_letter[c - 'A']) {
                        can_build = false;
                        break;
                    }
                }
                
                if (can_build) {
                    is_built[i] = true;                         
                    has_letter[abbreviations[i][0] - 'A'] = true;
                    made_progress = true;                       
                }
            }
        }
    }

    bool all_built = true;
    for (int i = 0; i < m; ++i) {
        if (!is_built[i]) {
            all_built = false;
            break;
        }
    }

    if (all_built) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
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