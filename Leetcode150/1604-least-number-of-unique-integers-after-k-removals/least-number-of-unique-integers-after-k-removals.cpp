class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> frequency;
        priority_queue<int, vector<int>, greater<int>> pq; 
        for (int num : arr) {
            frequency[num]++;
        }
        for (auto& pair : frequency) {
            pq.push(pair.second);
        }
        while (k > 0 && !pq.empty()) {
            int freq = pq.top();
            pq.pop();
            if (k >= freq) {
                k -= freq;
            } else {
                pq.push(freq - k);
                k = 0;
            }
        }
        int uniqueCount = pq.size();

        return uniqueCount;
    }
};
