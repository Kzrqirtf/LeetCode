class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        int l = s.length();
        vector<vector<int>> dp(l, vector<int>(l, 0));
        for (int len = 1; len <= l; len++) {
            for (int i = 0; i <= l - len; i++) {
                int j = i + len - 1;
                if (len == 1) {
                    dp[i][j] = 1; 
                } else if (s[i] == s[j] && (len == 2 || dp[i + 1][j - 1])) {
                    dp[i][j] = 1;
                }
            }
        }

        vector<string> currentPartition;
        findPartitions(0, s, dp, currentPartition, ans);
        return ans;
    }
    void findPartitions(int start, string &s, vector<vector<int>> &dp, 
                        vector<string> &currentPartition, vector<vector<string>> &ans) {
        int n = s.length();
        if (start == n) {
            ans.push_back(currentPartition);
            return;
        }
        for (int end = start; end < n; end++) {
            if (dp[start][end] == 1) {
                currentPartition.push_back(s.substr(start, end - start + 1));
                findPartitions(end + 1, s, dp, currentPartition, ans);
                currentPartition.pop_back();
            }
        }
    }
};
