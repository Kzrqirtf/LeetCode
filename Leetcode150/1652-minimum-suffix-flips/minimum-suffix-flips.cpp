class Solution {
public:
    int minFlips(string target)
    {
        int ans=0;
        int n = target.size();
        char curr = target[0];
        for(int i=0;i<n;i++)
        {
            if(i==0 && target[0]=='0')continue;
            if(i==0 && target[0]=='1')ans+=1;
            while(target[i]==curr && i<n)
            {
                i++;
            }
            if(target[i]!=curr && i<n)
            {
                curr=target[i];
                ans++;
            }
        }
        return ans;
        
    }
};