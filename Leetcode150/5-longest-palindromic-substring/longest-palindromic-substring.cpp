class Solution {
public:
    // void isPalindrome(string s, string &ans)
    // {
    //     int i=0,j=s.size()-1;
    //     bool k=true;
    //     while(i<=j)
    //     {
    //         if(s[i]!=s[j])
    //         {
    //             k=false;
    //             break;
    //         }
    //         i++;
    //         j--;
    //     }
    //     if(k==true)
    //     {
    //         if(s.size()>ans.size())
    //             ans=s;
    //     }
       
    // }
    int expandAroundCenter(string& s, int left, int right)
    {
        while (left>=0 && right<s.size() && s[left]==s[right])
        {
            left--;
            right++;
        }
        cout<< right <<" "<<left<<endl;

        return right - left - 1;
    }
    string longestPalindrome(string s)
    {
        // if(s.size()==1)return s;
        // string ans;
        // ans+=s[0];
        // int n=s.size();
        // for(int i=0;i<n;i++)
        // {
        //     for(int j=i+1;j<n;j++)
        //     {
        //         isPalindrome(s.substr(i,j-i+1),ans);
        //     }
        // }
        // return ans;
        if (s.empty()) {
            return "";
        }

        int start = 0, maxLength = 1;
        int n = s.size();
        int i,lenOdd,lenEven,len;
        for (i = 0; i < n; i++) {
            lenOdd = expandAroundCenter(s, i, i);
            lenEven = expandAroundCenter(s, i, i + 1);
            len = max(lenOdd, lenEven);
            if (len > maxLength) {
                start = i - (len - 1) / 2;
                maxLength = len;
            }
        }
        return s.substr(start, maxLength);
    }
};