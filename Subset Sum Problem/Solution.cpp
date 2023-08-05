// Link : https://practice.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1


// Code : 

class Solution{   
public:
    bool isSubsetSum(vector<int>arr, int W){
        // code here 
        int N = arr.size();
        int dp[N+1][W+1];
        memset(dp,-1,sizeof(dp));
        
        for(int i=0;i<N+1;i++) // poora first column 
        {
            dp[i][0]=1;
        }
        for(int j=1;j<W+1;j++) // poori first row .. first element chhod k
        {
            dp[0][j]=0;
        }
        
        // our matrix is ready
        int currElement;
        for(int i=1;i<N+1;i++)
        {
            for(int j=1;j<W+1;j++)
            {
                currElement = arr[i-1];
                if(currElement <= j)
                {
                    dp[i][j] = dp[i-1][j] == 1 || dp[i-1][j-currElement] ? 1 : 0; // row hmesha phle wali hi dekhni h 
                }
                else
                {
                    dp[i][j] = dp[i-1][j];
                }
                
                //cout << dp[i][j] << " ";
            }
            //cout << endl;
        }
        
        return dp[N][W]==1 ;
        
    }
};
