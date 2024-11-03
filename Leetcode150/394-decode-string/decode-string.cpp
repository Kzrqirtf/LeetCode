class Solution {
public:
    string decodeString(string s)
    {
        stack<pair<string,int>>st;
        int count=0;
        string ans;
        for(char x:s)
        {
            if(x=='['){
                st.push({ans,count});
                ans="";
                count=0;
            }
            else if(x==']'){
                auto [str,c]=st.top();
                st.pop();
                int t=c;
                string add;
                while(t--)add+=ans;
                ans=str+add;
            }
            else if(x<='9' and x>='0'){
                count=10*count+(x-'0');
            }
            else{
                ans+=x;
            }
        }
        return ans;
    }
};