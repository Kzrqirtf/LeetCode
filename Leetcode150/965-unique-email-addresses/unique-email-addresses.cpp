class Solution {
public:
    int numUniqueEmails(vector<string>& emails)
    {
        unordered_set<string> s;

        for (auto email : emails) {
            int atPos = email.find('@');
            string local = email.substr(0, atPos);
            string domain = email.substr(atPos,email.size());  
            string processedLocal;
            for (char ch : local) {
                if (ch == '+') break;
                if (ch != '.') processedLocal += ch;
            }
            s.insert(processedLocal + domain);
        }

        return s.size();
    }
        
    
};