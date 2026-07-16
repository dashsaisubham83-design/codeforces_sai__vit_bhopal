#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<vector<int>> pref(n + 1, vector<int>(4, 0));
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        pref[i + 1] = pref[i];
        pref[i + 1][a[i]]++;
    }

    // Iterate through all possible first cut positions i
    // Left part is [0, i), Middle is [i, j), Right is [j, n)
    for (int i = 1; i <= n - 2; ++i) {
        int ones1 = pref[i][1];
        int twos1 = pref[i][2];
        int threes1 = pref[i][3];
        
        // Condition 1: Left part
        if (ones1 >= twos1 + threes1) {
            // Now check if there exists a j such that middle and right satisfy conditions
            for (int j = i + 1; j <= n - 1; ++j) {
                int ones2 = pref[j][1] - pref[i][1];
                int twos2 = pref[j][2] - pref[i][2];
                int threes2 = pref[j][3] - pref[i][3];
                
                // Condition 2: Middle part
                if (ones2 + twos2 >= threes2) {
                    return true; // Found a valid split
                }
            }
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        if (solve()) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}