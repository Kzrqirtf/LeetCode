class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int> alpha(26,0);
        for(auto i:sentence)
        {
            alpha[i-'a']++;
        }
        for(auto i: alpha)
            if(i==0)return false;
        return true;
        
    }
};