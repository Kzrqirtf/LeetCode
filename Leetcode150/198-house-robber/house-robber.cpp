// class Solution {
// public:
//     int robb(vector<int>&nums,int i,vector<int>&dp)
//     {
//         if(i>=nums.size())return 0;
//         if(dp[i]!=-1)return dp[i];
//         int pick1,pick2;
//         dp[i]=max(nums[i]+robb(nums,i+2,dp),0+robb(nums,i+1,dp));
//         return dp[i];
        
//     }
//     int rob(vector<int>& nums)
//     {
//         vector<int>dp(nums.size()+1,-1);
//         int i=0;
//         int ans;
//         ans = robb(nums,i,dp);
//         return ans;

        
//     }
// };
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0; // No houses to rob
        if (n == 1) return nums[0]; // Only one house to rob

        int prev2 = 0; // Maximum money robbed two houses back
        int prev1 = 0; // Maximum money robbed from the previous house
        int curr = 0;  // Current maximum

        for (int i = 0; i < n; ++i) {
            curr = max(nums[i] + prev2, prev1); // Rob current house or skip
            prev2 = prev1; // Update for the next iteration
            prev1 = curr;  // Update for the next iteration
        }

        return curr; // The final result
    }
};
