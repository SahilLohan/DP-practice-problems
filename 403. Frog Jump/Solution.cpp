// Link : https://leetcode.com/problems/frog-jump/description/


// Code : 
class Solution {
public:

    bool solve(int index,unordered_map<int,int>& mp,int target,int jump,vector<vector<int>>& dp,vector<int>& stones)
    {

        if(index==stones.size()-1)
        return true;
        if(index>stones.size()-1)
        return false;

        if(dp[index][jump]!=-1)
        {
            return dp[index][jump]==1?true:false;
        }
        // choices
        if(jump>0 && mp.find(stones[index]+jump-1)!=mp.end() && solve(mp[stones[index]+jump-1],mp,target,jump-1,dp,stones)) // less jump
        {
            dp[index][jump]=1;
            return true;
        }
        else if(jump>0 && mp.find(stones[index]+jump)!=mp.end() && solve(mp[stones[index]+jump],mp,target,jump,dp,stones))
        {
            dp[index][jump]=1;
            return true;
        }
        else if(mp.find(stones[index]+jump+1)!=mp.end() && solve(mp[stones[index]+jump+1],mp,target,jump+1,dp,stones))
        {
            dp[index][jump]=1;
            return true;
        }
        dp[index][jump]=0;
        return false;
    }
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        int target = stones[n-1];
        unordered_map<int,int> mp;

        vector<vector<int>> dp(n+2,vector<int> (2001,-1));
        for(int i=0;i<stones.size();i++)
        {
            mp[stones[i]] = i;
        }
        return solve(0,mp,target,0,dp,stones);
    }
};
