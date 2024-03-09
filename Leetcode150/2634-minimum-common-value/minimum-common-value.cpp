class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        //O(nlogm)
        //  int len2 = nums2.size() - 1;
        // for (int num : nums1) {
        //     int l = 0, r = len2;
        //     while (l <= r) {
        //         int m = l + (r - l) / 2;
        //         if (nums2[m] == num) {
        //             return num;
        //         } else if (nums2[m] < num) {
        //             l = m + 1;
        //         } else {
        //             r = m - 1;
        //         }
        //     }
        // }
        // return -1;   
        //O(N) but also takes space O(m)
        // unordered_set<int> nums2Set(nums2.begin(), nums2.end());

        // for (int num : nums1) {
        //     if (nums2Set.find(num) != nums2Set.end()) {
        //         return num;
        //     }
        // }

        // return -1;
        //most optimised
        int a = 0 , b = 0;
        bool flag = true;
        while(flag && a<nums1.size() && b<nums2.size())
        {
            if(nums1[a]<nums2[b])
            a++;
            else if(nums1[a]>nums2[b])
            b++;
            else
            flag = false;
        }
        return flag?-1 : nums1[a];
    }
};