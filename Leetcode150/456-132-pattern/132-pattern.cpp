class Solution {
public:
    bool find132pattern(vector<int>& nums)
    {
        // stack<int> st;
        // int i=0,count=0;
        // int n=nums.size();
        // for(auto i : nums)
        // {
        //     if(count==3)break;
        //     if(st.empty()){
        //         st.push(i);
        //         count++;
        //     }
        //     if(count==1 && st.top()>i)
        //     {
        //         st.pop();
        //         st.push(i);
        //         continue;
        //     }
        //     if(count==1 && i>st.top())
        //     {
        //         st.push(i);
        //         count++;
        //     }
        //     if(count==2)
        //     {
        //         if(i<st.top()){
        //             int c = st.top();
        //             st.pop();
        //             if(i>st.top())count++;
        //             else{
        //                 while(!st.empty())
        //                     st.pop();
        //                 st.push(i);
        //                 count=1;
        //             }
        //         }
        //         else if(i>st.top()){
        //             st.pop();
        //             st.push(i);
        //         }
        //     }
        // }
        // return (count==3)?true:false;

        stack<int> s;
        int third=INT_MIN;
        for(int i=nums.size()-1;i>=0;i--)
        {
            if(nums[i]<third)return true;
            while(!s.empty() && s.top()<nums[i])
            {
                third=s.top();
                s.pop();
            }
            s.push(nums[i]);
        }
        return false;
        
    }
};