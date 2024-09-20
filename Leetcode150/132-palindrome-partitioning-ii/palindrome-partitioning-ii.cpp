class Solution {
public:
    int minCut(string s) {
        int l = s.length();
        vector<vector<int>> dp(l, vector<int>(l, 0));
        vector<int> cut(l, INT_MAX);  
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

        for (int i = 0; i < l; i++) {
            if (dp[0][i]) {
                cut[i] = 0; 
            } else {
                for (int j = 1; j <= i; j++) {
                    if (dp[j][i]) {
                        cut[i] = min(cut[i], cut[j - 1] + 1);
                    }
                }
            }
        }

        return cut[l - 1];  
    }
};
