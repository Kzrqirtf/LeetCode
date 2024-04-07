//Without Stack
// class Solution {
// public:
//     string minRemoveToMakeValid(string s) 
//     {
//         int l=0,r=0,n = s.size();
//         for (int i=0;i<n;i++){
//             char c=s[i];
//             if(i < n && (c != '(' && c != ')'))
//             {
//                 continue;

//             }

//             if(s[i]==')' && l==0)continue;
//             if(s[i]=='(')l++;
//             else if(s[i]==')' && l>r)r++;
//         }
//         int lc=0,rc=0;
//         l=r;

//         cout<<r;
//         string ans="";
//         int i=n-1;
//         while(i>=0){
//             char c=s[i];
//             if(i >= 0 && (c != '(' && c != ')'))
//             {
//                 ans=c+ans;
//                 i--;
//                 continue;

//             }
//             else if(l==r){
//                 if(l<r && s[i]=='('){ans='('+ans;lc++;l--;}
//             }
//             else if(s[i]=='(' && l>0)
//             {ans='('+ans;lc++;l--;}
//             if(s[i]==')' && r>0){ans=')'+ans;rc++;r--;}
//             i--;
//         }
//         return ans;
//     }
// };
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') {
                st.push(i);
            } else if (s[i] == ')') {
                if (!st.empty()) {
                    st.pop();
                } else {
                    s[i] = '*'; 
                }
            }
        }
        while (!st.empty()) {
            s[st.top()] = '*';
            st.pop();
        }
        string result = "";
        for (char c : s) {
            if (c != '*') {
                result += c;
            }
        }
        
        return result;
    }
};

