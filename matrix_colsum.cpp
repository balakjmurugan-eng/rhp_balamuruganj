#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


pair<long long, long long> getMax(vector<vector<long long>>& dp, int R, int col)
{
    long long fMax = max(dp[0][col], dp[1][col]);
    long long sMax = min(dp[0][col], dp[1][col]);

    for(int i = 2; i < R; i++)
    {
        if(dp[i][col] > fMax)
        {
            sMax = fMax;
            fMax = dp[i][col];
        }
        else if(dp[i][col] > sMax)
        {
            sMax = dp[i][col];
        }
    }

    return {fMax, sMax};
}

int main()
{
    int R, C;
    cin >> R >> C;

    vector<vector<int>> a(R, vector<int>(C));
    vector<vector<long long>> dp(R, vector<long long>(C, 0));

    
    for(int i = 0; i < R; i++)
    {
        for(int j = 0; j < C; j++)
        {
            cin >> a[i][j];

            if(j == 0)
                dp[i][j] = a[i][j];
        }
    }

    pair<long long, long long> mx = getMax(dp, R, 0);
    long long fMax = mx.first;
    long long sMax = mx.second;

    
    for(int j = 1; j < C; j++)
    {
        for(int i = 0; i < R; i++)
        {
            if(dp[i][j - 1] == fMax)
                dp[i][j] = a[i][j] + sMax;
            else
                dp[i][j] = a[i][j] + fMax;
        }

        mx = getMax(dp, R, j);
        fMax = mx.first;
        sMax = mx.second;
    }

    cout << fMax << endl;

    return 0;
}
