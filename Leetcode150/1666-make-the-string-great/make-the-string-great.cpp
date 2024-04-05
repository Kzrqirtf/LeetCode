class Solution {
public:
    string makeGood(string s) {
        stack<char> st;
        int n=s.size();
        int i=0;    //s=leEeetcode
        while(n)    
        {
            if(!st.empty())
            {
                if(st.top()==s[i]-32||st.top()==s[i]+32)
                {
                    cout<<st.top() <<" "<<s[i];
                    st.pop();
                    n--;
                    i++;
                    continue;
                }
            }
            st.push(s[i]);
            i++;
            n--;
        }
        string ans="";
        while(!st.empty())
        {
            ans = st.top()+ans;
            st.pop();
        }
        return ans;
        
    }
};