// Link : https://practice.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1


// Code : 
class Solution{
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        int dp[N+1][W+1];
        memset(dp,0,sizeof(dp));
        
        for(int i=1;i<N+1;i++)
        {
            for(int j=1;j<W+1;j++)
            {
                if(wt[i-1] <= j)
                {
                    dp[i][j] = max(dp[i-1][j] , val[i-1] + dp[i][j - wt[i-1]]);
                }
                else
                {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        return dp[N][W];
    }
};
