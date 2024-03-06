class Solution {
public:
    int removeElement(vector<int>& nums, int val)
    {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            if (nums[left] == val) {
                nums[left] = nums[right];
                right--;
            } else {
                left++;
            }
        }
    return left;
    }
};