class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle)
    {

        // int path=0;
        // int a=0;
        // for(int i=0;i<triangle.size();i++)
        // {
        //     if(i==0)
        //         path+=triangle[0][0];
        //     else if(i>0)
        //     {
        //         int k=min(triangle[i][a],triangle[i][a+1]);
        //         if(k==triangle[i][a+1])
        //             a=a+1;
        //         path+=k;
        //     }
        // }
        // return path;

        int n = triangle.size();
        for(int i =n-2;i>=0;i--)
        {
            for(int j=0;j<=i;j++)
            {
                triangle[i][j]+=min(triangle[i+1][j],triangle[i+1][j+1]);
            }
            
        }
        return triangle[0][0];
    }
};