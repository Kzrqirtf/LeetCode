class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> hash(26,0);
        int n = s.size();
        for (char c : s) {
            hash[c - 'a']++;
        }
        
        stack<char> st;
        vector<bool> visited(26, false); 
        
        for (int i = 0; i < n; ++i) {
            hash[s[i] - 'a']--; 
            if (visited[s[i] - 'a']) {
                continue;
            }
            while (!st.empty() && s[i] < st.top() && hash[st.top() - 'a'] > 0) {
                visited[st.top() - 'a'] = false;
                st.pop();
            }
            st.push(s[i]);
            visited[s[i] - 'a'] = true;
        }
        string result = "";
        while (!st.empty()) {
            result = st.top() + result;
            st.pop();
        }
        
        return result;
    }
};