class Solution:
    def customSortString(self, order: str, s: str) -> str:
        ans = ""
        counts = {}
        for char in s:
            if char in order:
                counts[char] = counts.get(char, 0) + 1
            else:
                ans += char
        
        for char in order:
            if char in counts:
                ans += char * counts[char]
        
        return ans
