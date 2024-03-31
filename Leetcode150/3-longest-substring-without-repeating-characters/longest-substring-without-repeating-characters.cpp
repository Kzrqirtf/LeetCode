class Solution {
public:
        
    int lengthOfLongestSubstring(string s)
    {
        // int m=0;
        
        // for(int i=0;i<s.length();++i)
        // {
        //     set <char> v;
        //     int j=i;
        //     while(v.size()==j-i && j<s.length())
        //     {
        //         v.insert(s[j]);
        //         j++;
        //     }
        //     int a=v.size();
        //     m=max(m,a);
    vector < int > mpp(256, -1);

      int left = 0, right = 0;
      int n = s.size();
      int len = 0;
      while (right < n) {
        if (mpp[s[right]] != -1)
          left = max(mpp[s[right]] + 1, left);

        mpp[s[right]] = right;

        len = max(len, right - left + 1);
        right++;
      }
      return len;
            
        // }
        // return m;
    }

}; 
    