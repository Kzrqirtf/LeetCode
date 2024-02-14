class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums)
    {
        vector<int> positive;
        vector<int> negative;
        vector<int> ans;
        for(auto i : nums)
        {
            if(i>=0)
                positive.push_back(i);
            else
                negative.push_back(i);
        }
        int n = nums.size();
        int i=0,j=0;
        while(n)
        {
            if(n%2 == 0)
            {
                ans.push_back(positive[i++]);
            }
            else
                ans.push_back(negative[j++]);
            n--;

        }
        return ans;
        /*
        int n=arr.size();
        vector<int>v(n);
        int j=0;int k=1;
	    for(int i=0;i<n;i++){
	        if(arr[i]>=0){
                v[j]=arr[i];
                j+=2;

            }
	        else {
                 v[k]=arr[i];
                k+=2;
                
            }
	    }
        return v;
        */
        
    }
};