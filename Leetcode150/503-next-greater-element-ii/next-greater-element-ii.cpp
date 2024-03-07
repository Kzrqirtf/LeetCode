class Solution {
public:
    // vector<int> nextGreaterElements(vector<int>& nums)
    // {
    //     int i=0,n=nums.size();
    //     vector<int> ans(n,0);
    //     while(i<n)
    //     {
    //         if(i+1<n && i-1>=0 && (nums[i-1]==nums[i+1]))
    //         {
    //             break;
    //         }
    //         i++;
    //     }
    //     if(i==n)i=n-1;
    //     int break_point = i;
    //     cout<<break_point;
    //     stack<int> st;
    //     while(i>=0)
    //     {
    //         while(!st.empty() && st.top()<=nums[i])
    //         {
    //             st.pop();
    //         }
    //         if(st.empty())
    //         {
    //             ans[i]=-1;
    //         }
    //         else ans[i]=st.top();
    //         st.push(nums[i]);
    //         i--;
    //     }
    //     if(break_point<=n-1)
    //     {
    //         int k=break_point+1;
    //         while(k<n)
    //         {
    //             ans[k++]=ans[break_point-1];
    //             break_point--;
    //         }
    //     }
    //     return ans;
    // }
    vector<int> nextGreaterElements(vector<int>& a) {
        int n = a.size();
        vector<int>v(n,-1);
        stack<int>st;
        for(int i = 2*n - 1; i >= 0; i--)
        {
            while(!st.empty() && (a[i%n] >= st.top()))
            {
                st.pop();
            }
            if(!st.empty() && (i < n))
            {
                v[i] = st.top();
            }
            st.push(a[i%n]);
        }
        return v;
    }
    
};