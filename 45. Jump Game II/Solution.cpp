// https://leetcode.com/problems/jump-game-ii/


// Code : 
class Solution {
public:
    
    long long solve(int index,vector<int>& nums,vector<long long>& ans)
    {
        if(ans[index]!=-1) return ans[index];
        if(index>=nums.size()-1) return 0;

        int jump_limit = nums[index];
        // other than this it can have next jump from 
        long long ret=INT_MAX;

        for(int i=1;index+i<nums.size() && i<=jump_limit;i++)
        {
            ret = ret<1+solve(index+i,nums,ans) ? ret : 1+solve(index+i,nums,ans);
        }

        return ret;

    }
    int jump(vector<int>& nums) {
        if(nums.size()==1) return 0;
        vector<long long> ans(nums.size(),-1);

        for(int index = nums.size()-2;index>=0;index--)
        {
            ans[index] = solve(index,nums,ans);
        }

        return ans[0];

    }
};
