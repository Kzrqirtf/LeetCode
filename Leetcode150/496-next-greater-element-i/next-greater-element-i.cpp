class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        stack<int> stk;
        unordered_map<int,int> mpp;
        
        for (int i = nums2.size() - 1; i >= 0; i--) {
            while (!stk.empty() && stk.top() <= nums2[i])
                stk.pop();
            
            mpp[nums2[i]] = stk.empty() ? -1 : stk.top();
            stk.push(nums2[i]);
        }
        
        for (auto i : nums1) {
            ans.push_back(mpp[i]);
        }
        
        return ans;
    }
};
