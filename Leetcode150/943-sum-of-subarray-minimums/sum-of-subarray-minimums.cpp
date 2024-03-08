class Solution {
public:
    int sumSubarrayMins(vector<int>& arr)
    {
        int ans=0;
        int n=arr.size();
        vector<int> Ls(n,-1);
        vector<int> Rs(n,n);
        stack<int> st;
        long long mod=1e9+7;
        int i=n-1;
        while(i>=0)
        {
            while(!st.empty() && arr[i]<arr[st.top()])
            {
                st.pop();
            }
            if(!st.empty())Rs[i]=st.top();
            st.push(i);
            i--;
        }
        while(!st.empty())st.pop();
        i=0;
        while(i<n)
        {
            while(!st.empty() && arr[i]<=arr[st.top()])
            {
                st.pop();
            }
            if(!st.empty())Ls[i]=st.top();
            st.push(i);
            i++;
        }
        for(auto i:Ls)cout<<i<<" ";
        cout<<endl;
        for(auto i:Rs)cout<<i<<" ";
        cout<<endl;
        int sum = 0;
        for(int i = 0; i < n; i++){

            long long ls = i- Ls[i];   
            long long rs = Rs[i]-i;

            long long TotalWays = ls*rs;

            long long totalSum = arr[i]*TotalWays;

            sum = (sum+totalSum)%mod;   
        }
        return sum;
    }
};