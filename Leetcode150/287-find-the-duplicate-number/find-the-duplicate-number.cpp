class Solution {
public:
    int findDuplicate(vector<int>& nums)
    {
        int ans=0;
        // int maxi = INT_MIN;
        // for(auto i:nums)
        // {
        //     maxi=max(i,maxi);
        // }
        // vector<int> count(maxi+1,0);
        // for(int i=0;i<nums.size();i++)
        // {
        //     count[nums[i]]++;
        //     if(count[nums[i]]>1)
        //     {
        //         ans=nums[i];
        //         break;
        //     }
        // }
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            int index = nums[i] % n;
            nums[index]+=n;
        }
        for(int i=0;i<n;i++)
        {
            if(nums[i]/n >= 2)
                ans=i;
        }
       
        return ans;
    }
};