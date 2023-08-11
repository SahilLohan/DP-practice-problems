// Link : https://leetcode.com/problems/target-sum/


// Code : 

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=0;
        int n = nums.size();
        for(auto num:nums)
        {
            sum += num;
        }

        int diff = target;

        sum = sum + diff;

        if(sum%2 != 0 || sum < 0) return 0;
        else sum = sum/2;

        // now it is same as a subset sum problem 
        int dp[n+1][sum + 1];

        dp[0][0] = 1;
        for(int i=1;i<sum +1;i++)
        {
            dp[0][i] = 0;
        }
        // all set

        for(int i=1;i<n+1;i++)
        {
            for(int j=0;j<sum +1;j++)
            {
                if(nums[i-1] <= j)
                {
                    dp[i][j] = dp[i-1][j] + dp[i-1][j - nums[i-1]];
                }
                else
                {
                    dp[i][j] = dp[i-1][j];                
                }
            }
        }

        for(int i=0;i<n+1;i++)
        {
            cout << "i : " << i  << " -> ";
            for(int j=0;j<sum+1;j++)
            {
                cout << dp[i][j] << " ";
            }
            cout << "\n";
        }

        return dp[n][sum];

    }
};
