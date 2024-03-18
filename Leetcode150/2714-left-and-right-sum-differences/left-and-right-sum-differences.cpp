class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        vector<int> leftSum(nums.size(),0),RightSum(nums.size(),0);
        vector<int> answer;
        int n = nums.size();
        int suml=nums[0],sumr=nums[n-1],i;
        int j=n-1;
        for(i=1;i<n;i++)
        {
            leftSum[i]=suml;
            suml+=nums[i];
            j--;
            RightSum[j]=sumr;
            sumr+=nums[j];
            
        }
        for(int i=0;i<n;i++)
        {
            cout<<RightSum[i]<< " ";
        }
        for(int i=0;i<n;i++)
        {
            int k= abs(leftSum[i]-RightSum[i]);
            answer.push_back(k);
        }
        return answer;
    }
};