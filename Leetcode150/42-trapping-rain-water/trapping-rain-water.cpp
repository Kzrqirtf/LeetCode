class Solution {
public:
//MINIMUM VALUE FROM RIGHT HIGHEST AND LEFT HEIGHTEST,SUBTRACTED BY SELF VALUE 
    int trap(vector<int>& height)
    {
        int n=height.size();
        vector<int> left(n),right(n);
        int trap=0;
        int j=n-2;
        left[0]=height[0];
        right[n-1]=height[n-1];
        for(int i=1;i<n;i++)
        {
            left[i]=max(left[i-1],height[i]);
            right[j]=max(height[j],right[j+1]);
            j--;       
        }
        for(int i=0;i<n;i++)
        {
            trap+=min(left[i],right[i])-height[i];

        }
        return trap;
        
    }
};