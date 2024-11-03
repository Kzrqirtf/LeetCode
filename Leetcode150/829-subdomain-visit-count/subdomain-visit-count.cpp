
class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int> mp;
        for (auto dom : cpdomains) {
            int i = 0, num = 0;

            // Parse the count at the beginning
            while (i < dom.size() && isdigit(dom[i])) {
                num = num * 10 + (dom[i] - '0');
                ++i;
            }
            // Skip the space after the count
            ++i;

            // Now, `dom.substr(i)` will be the domain part
            string domain = dom.substr(i);
            mp[domain] += num;  // Add the full domain count

            // Process subdomains
            for (int j = 0; j < domain.size(); ++j) {
                if (domain[j] == '.') {
                    string subdomain = domain.substr(j + 1);
                    mp[subdomain] += num;  // Add count to each subdomain
                }
            }
        }

        // Prepare the result vector
        vector<string> ans;
        for (const auto& [key, value] : mp) {
            ans.push_back(to_string(value) + " " + key);
        }

        return ans;
    }
};

