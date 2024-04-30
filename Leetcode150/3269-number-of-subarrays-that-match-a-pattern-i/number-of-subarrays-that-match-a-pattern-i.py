class Solution(object):
    def countMatchingSubarrays(self, nums, pattern):
        n = len(nums)
        m = len(pattern)
        count = 0

        for i in range(n - m):
            match = True
            for j in range(m):
                if pattern[j] == 1 and nums[i + j + 1] <= nums[i + j]:
                    match = False
                    break
                elif pattern[j] == 0 and nums[i + j + 1] != nums[i + j]:
                    match = False
                    break
                elif pattern[j] == -1 and nums[i + j + 1] >= nums[i + j]:
                    match = False
                    break
            if match:
                count += 1

        return count
