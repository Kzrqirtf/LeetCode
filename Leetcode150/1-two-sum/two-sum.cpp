class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        vector<int> v=nums,sol;
        sort(nums.begin(),nums.end());
        int j=nums.size()-1,i=0;
        while( i < j)
        {
            if(nums[i]+nums[j]==target){break;}
            if(nums[i]+nums[j]>target)j--;
            else i++;
        }
        int a=2;
        for(int k=0;k< v.size();k++)
        {
            if(a==0)break;
            if(v[k]==nums[i]||nums[j]==v[k])
            {
                sol.push_back(k);
                a--;
            }
        }
        
        return sol;
        // int n= arr.size();
        // unordered_map<int, int> mpp;
        // for (int i = 0; i < n; i++)
        // {
        //     int num = arr[i];
        //     int moreNeeded = target - num;
        //     if (mpp.find(moreNeeded) != mpp.end()) {
        //         return {mpp[moreNeeded], i};
        //     }
        //     mpp[num] = i;
        // }
        // return { -1, -1};
        
    }
};