// Link :https://leetcode.com/problems/house-robber/


// Code : 
class Solution {
public:
    int dp[101];

    int rob(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return solve(nums,nums.size()-1);
    }

    int solve(vector<int>& nums,int index)
    {
        if(index<0)return 0;
        else
        {
            if(dp[index]!=-1) return dp[index];
            else
            {
                return dp[index] = max(nums[index]+solve(nums,index-2) , solve(nums,index-1));
            }
        }
    }

};
