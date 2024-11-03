// class Solution {
// public:
//     vector<string> subdomainVisits(vector<string>& cpdomains)
//     {
//         unordered_map<string,int> mp;
//         int num;
//         for(auto dom: cpdomains)
//         {
//             int i;
//             num=0;
//             for(i=0;i<dom.size();i++)
//             {
//                 if(dom[i]<='9' && dom[i]>='0')
//                     num = num * 10 + (dom[i] - '0');
//                 else break;
//             }
//             cout<<num;
//             // num=stoi(dom.substr(0,i));
//             i++;
//             for(i;i<dom.size();i++){
//                 if(mp.find(dom)!=mp.end())
//                     mp[dom]+=num;
//                 else mp[dom]=num;
//                 if(dom[i]=='.')
//                 {
//                     string d ;
//                     d= dom.substr(i+1,dom.size());
//                     if(mp.find(d)!=mp.end())
//                     mp[d]+=num;
//                     else mp[d]=num;
//                 }
//             }

//         }
//         vector<string>ans;
//         for (auto [key, value] : mp) {
//             string a = to_string(value) + " " + key;
//             ans.push_back(a);
// }

//         return ans;
        
//     }
// };
#include <vector>
#include <string>
#include <unordered_map>
#include <sstream>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int> mp;

        for (auto dom : cpdomains) {
            // Parse the count at the beginning
            int num = 0;
            int i = 0;
            while (i < dom.size() && isdigit(dom[i])) {
                num = num * 10 + (dom[i] - '0');
                ++i;
            }
            
            // Skip the space
            while (i < dom.size() && dom[i] == ' ') {
                ++i;
            }

            // Extract the full domain and update counts for each subdomain
            string domain = dom.substr(i);
            while (true) {
                mp[domain] += num;

                // Find the next subdomain
                size_t pos = domain.find('.');
                if (pos == string::npos) break;

                domain = domain.substr(pos + 1);
            }
        }

        // Prepare the result vector
        vector<string> ans;
        for (auto [key, value] : mp) {
            ans.push_back(to_string(value) + " " + key);
        }

        return ans;
    }
};
