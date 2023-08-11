// Link  : https://practice.geeksforgeeks.org/problems/rod-cutting0840/1


// Code :
class Solution{
  public:
    int cutRod(int price[], int n) {
        //code here
        // index + 1 is the length i.e. weight
        
        int dp[n+1][n+1];
        memset(dp,0,sizeof(dp));
        
        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<n+1;j++)
            {
                if(i <= j) // i - mtlb jo length ab choose krenge 
                {
                    dp[i][j] = max(dp[i-1][j] , price[i-1] + dp[i][j - i] );
                }
                else
                {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        return dp[n][n];
    }
};
