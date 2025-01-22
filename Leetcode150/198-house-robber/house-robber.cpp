class Solution {
public:
    int robb(vector<int>&nums,int i,vector<int>&dp)
    {
        if(i>=nums.size())return 0;
        if(dp[i]!=-1)return dp[i];
        int pick1,pick2;
        dp[i]=max(nums[i]+robb(nums,i+2,dp),0+robb(nums,i+1,dp));
        return dp[i];
        
    }
    int rob(vector<int>& nums)
    {
        vector<int>dp(nums.size()+1,-1);
        int i=0;
        int ans;
        ans = robb(nums,i,dp);
        return ans;

        
    }
};