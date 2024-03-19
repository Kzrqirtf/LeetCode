class Solution {
public:
    int minOperations(vector<int>& nums, int k)
    {
        //find number of elements smaller than k
        int ans=0;
        for(auto i:nums) 
        {
            if(i<k)ans++;
        }
        return ans;
        
    }
};