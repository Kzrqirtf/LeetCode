class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums)
    {
        vector<int> ans;
        int mul=1, zer=0,every_zero=0,c=0;
        for(auto i: nums){
            if (i!=0)
            {
                mul*=i;
            }
            else {c++;zer=1;}

        }
        for(auto i:nums)
        {
            if(i==0)every_zero=1;
            else{
                every_zero=0;
                break;
            }
        }
        if(every_zero||c>1)
        {
            vector<int>as(nums.size(),0);
            return  as;
        }
        if(!zer){
            for(auto i : nums)
                ans.push_back(mul/i);}
        else{
            for(auto i: nums)
            {
                if(i==0)ans.push_back(mul);
                else ans.push_back(0);
            }

        }
        return ans;

        
        
    }
};