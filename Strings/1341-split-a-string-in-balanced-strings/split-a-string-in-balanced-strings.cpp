class Solution {
public:
    int balancedStringSplit(string s)
    {
        int count=0;
        int R=0,L=0;
        for(int i =0 ;i<s.size();i++)
        {
            if(s[i]=='R')
            {
                R++;
            }
            if(s[i]=='L')
            {
                L++;
            }
            if(R==L && (R!=0))
            {
                count++;
                R=0;
                L=0;
            }
            
        }
        return count;
        
    }
};