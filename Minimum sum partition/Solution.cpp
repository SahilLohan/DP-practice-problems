// Link : https://practice.geeksforgeeks.org/problems/minimum-sum-partition3317/1

// Code : 

class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int sum =0;
	    
	    for(int i=0;i<n;i++)
	    {
	        sum += arr[i];
	    }
	    
	    int cols = sum/2 + 1;
	    
	    bool dp[n+1][cols];
	    memset(dp,false,sizeof(dp));
	    
	    for(int i=0;i<n+1;i++)
	    {
	        dp[i][0]=true;
	    }
	    
	    for(int i=1;i<n+1;i++)
	    {
	        for(int j=1;j<cols;j++)
	        {
	            if(arr[i-1] <= j)
	            {
	                dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
	            }
	            else
	            {
	                dp[i][j] = dp[i-1][j];
	            }
	        }
	    }
	    
	    for(int j=cols-1;j>=0;j--)
	    {
	        if(dp[n][j])
	        {
	            return sum - (2*j);
	        }
	    }
	    
	    return 0;
	} 
};
