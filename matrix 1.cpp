#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> a(n, vector<int>(m));
    vector<vector<int>> dp(n, vector<int>(m));

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> a[i][j];
            if(i == 0)
                dp[i][j] = a[i][j]; 
            


    
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int mx = 0;

            for(int k = 0; k < m; k++) {
                if(k != j)
                    mx = max(mx, dp[i-1][k]);
            }

            dp[i][j] = a[i][j] + mx;
        }
    }

    
    cout << "DP Matrix:\n";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++)
            cout << dp[i][j] << " ";
        cout << endl;
    }

    int ans = 0;
    for(int j = 0; j < m; j++)
        ans = max(ans, dp[n-1][j]);

    cout << "Maximum Sum = " << ans << endl;

    return 0;
}
