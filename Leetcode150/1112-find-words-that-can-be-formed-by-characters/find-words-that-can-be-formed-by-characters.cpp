class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int>freq(26);
        // getting to know the 
        for(int i =0;i<chars.size();i++)
        {
            freq[chars[i]-'a']++;
        }
        int result = 0 ; 
        for(auto w :words)
        {
            int frequency[26]= {};
            bool flag = 0 ;
            for(auto c:w)
            {
                frequency[c-'a']++;
                //  word cannot be made 
                if(frequency[c-'a'] > freq[c-'a'])
                {
                    flag= 1;
                    break;
                }
            }
            if(flag ==0)
            {
                result += w.size();
            }
        }
        return result;
    }
};