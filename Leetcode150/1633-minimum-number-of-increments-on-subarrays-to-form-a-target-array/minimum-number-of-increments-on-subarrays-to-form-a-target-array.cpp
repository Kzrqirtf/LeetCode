class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        stack<int> st;
        st.push(0);
        int count = 0;
        for (int i : target) {
            if (i > st.top())
                count += i - st.top();
            while (st.top() > i)
                st.pop();
            st.push(i);
        }
        return count;
    }
};