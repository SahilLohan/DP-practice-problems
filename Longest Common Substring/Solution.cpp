// Link : https://practice.geeksforgeeks.org/problems/longest-common-substring1452/1


// Code : 
class Solution{
    public:
    
    int solve(string& a,string& b,int i,int j,int n,int m,int len,vector<vector<int>>& dp)
    {
        
        if(i>=n || j>=m || i<0 || j<0)
        return len;
        if(dp[i][j]!=-1) return dp[i][j];
        
        if(a[i]==b[j])
        {
            return dp[i][j] = 1+solve(a,b,i-1,j-1,n,m,len,dp);
        }
        else
        return dp[i][j]=0;
    }
    int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        int ans=0;
        vector<vector<int>> dp(n+1,vector<int> (m+1,-1));
        // your code here
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                ans =  max(ans , solve(S1,S2,i,j,n,m,0,dp));
            }
        }
        
        return ans;
    }
}
