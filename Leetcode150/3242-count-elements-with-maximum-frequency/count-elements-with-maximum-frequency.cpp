class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int maxi=nums[0];
        for(auto i:nums)
        {
            if(i>maxi)maxi=i;
        }
        vector<int> hash(maxi+1,0);
        for(auto i: nums)
        {
            hash[i]++;
        }
        int max_freq=0;
        for(auto i:hash)
        {
            max_freq=max(max_freq,i);
        }
        int ans=0;
        for(auto i : nums)
        {
            if(hash[i]==max_freq)ans++;
        }
        return ans;
    }
};