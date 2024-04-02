class Solution {
public:
    bool isIsomorphic(string s, string t)
    {
         /*unordered_map<char, char> mp, mp2;
        for (int i=0; i<s.length(); ++i) {
            if (mp[s[i]] && mp[s[i]]!=t[i]) return false;
            if (mp2[t[i]] && mp2[t[i]]!=s[i]) return false;
            mp[s[i]]=t[i];
            mp2[t[i]]=s[i];
        }
        return true;
    }*/
        if(s.length()!=t.length())return false;
        unordered_map<char,char> map1,map2;
        for(int i=0;i<s.length();i++)
        {
            map1[s[i]]=t[i];
            map2[t[i]]=s[i];
        }
        for(int i=0;i<s.length();i++)
        {
            if (map1[s[i]] && map1[s[i]]!=t[i]) return false;
            if (map2[t[i]] && map2[t[i]]!=s[i]) return false;
        }
        return true;

        
        
    }
};