class Solution {
public:
    int lengthOfLastWord(string s)
    {
        int n = s.size()-1;
        int ans=0;
        while(s[n]==' ')
            n--;
        while(n>=0&&s[n--]!=' ' )
            ans++;
        return ans;
        
    }
};