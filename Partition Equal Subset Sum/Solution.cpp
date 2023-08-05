// Link : https://leetcode.com/problems/partition-equal-subset-sum/


// Code :
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum =0;
        for(auto num : nums)
        {
            sum += num;
        }

        if(sum % 2!=0) return false;
        else
        {
            sum = sum/2;

            // now it has become the target sum problem

            int dp[n+1][sum+1];
            memset(dp,-1,sizeof(dp));

            for(int i=0;i<n+1;i++) dp[i][0]=1;
            for(int j=1;j<sum+1;j++) dp[0][j]=0; 

            // setup done

            for(int i=1;i<n+1;i++)
            {
                for(int j=1;j<sum+1;j++)
                {
                    if(nums[i-1] <= j)
                    {
                        if(dp[i-1][j]==1 || dp[i-1][j-nums[i-1]]==1)
                            dp[i][j] = 1;
                        else
                            dp[i][j] = 0;
                    }
                    else
                    {
                        dp[i][j] = dp[i-1][j];
                    }
                }
            }
            return dp[n][sum];
        }
    }
};
