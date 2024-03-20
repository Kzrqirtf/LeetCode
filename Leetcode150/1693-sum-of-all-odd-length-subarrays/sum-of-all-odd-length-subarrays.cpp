class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr)
    {
        int total_sum = 0;
        int n = arr.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                if ((j - i) % 2 == 0) {  
                    for (int k = i; k <= j; ++k) {
                        total_sum += arr[k];
                    }
                }
            }
        }
        
        return total_sum;
        
    }
};