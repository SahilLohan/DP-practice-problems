// Link : https://leetcode.com/problems/coin-change/description/

// Code : 

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        int dp[n+1][amount+1];

        for(int i=0;i<n+1;i++)
        {
            dp[i][0] = 0;
        }
        for(int j=1;j<amount+1;j++)
        {
            dp[0][j] = amount+1;
        }
        // for(int j=0;j<amount+1;j++)
        // {
        //     dp[0][j] = j%coins[0] && j>coins[0] ? j/coins[0] : INT_MAX-1;
        // } 

        // all set

        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<amount+1;j++)
            {
                if(coins[i-1] <= j)
                {
                    dp[i][j] = min(1+dp[i][j - coins[i-1]] , dp[i-1][j]);
                }
                else
                {
                    dp[i][j] = dp[i-1][j];
                }
                // cout << dp[i][j] << " ";
            }
            // cout << endl;
        }

        return dp[n][amount]>amount ? -1 : dp[n][amount];
    }
};
