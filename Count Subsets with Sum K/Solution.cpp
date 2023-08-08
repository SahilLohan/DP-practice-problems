// Link  : https://www.codingninjas.com/studio/problems/count-subsets-with-sum-k_3952532?leftPanelTab=0


// Code : 
int findWays(vector<int>& arr, int k)
{
	// Write your code here.
	int size=arr.size();
	long long int dp[size+1][k+1];

	memset(dp,-1,sizeof(dp));
	for(int i=0;i<size+1;i++)
		dp[i][0] = 1;
	for(int j=1;j<k+1;j++)
		dp[0][j] = 0;

	for(int i=1;i<size+1;i++)
	{
		for(int j=1;j<k+1;j++)
		{
			if(arr[i-1]<= j )
			{
				// cout << arr[j-1] << " : " << dp[i-1][j]+dp[i-1][j-arr[j-1]] << endl;
				dp[i][j]=dp[i-1][j]+dp[i-1][j-arr[i-1]];
			}
			else
			{
				dp[i][j]=dp[i-1][j];
			}
		}
	}

	// for(int i=0;i<size+1;i++)
	// {
	// 	for(int j=0;j<k+1;j++)
	// 	{
	// 		cout << dp[i][j] << " " ;
	// 	}
	// 	cout << endl;
	// }

	return dp[size][k] % 1000000007;
}
