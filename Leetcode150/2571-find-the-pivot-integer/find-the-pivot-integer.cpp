class Solution {
public:
    int summation(int i,bool t,int n)
    {
        if(t)
        {
            return (i*(i+1))/2;
        }
        return ((n*(n+1))/2) - ((i*(i+1))/2)+i;
    }
    int pivotInteger(int n)
    {
        int i=1;
        int sum1=0,sum2=0;
        while(i<=n)
        {
            if(summation(i,true,n) == summation(i,false,n))
                return i;
            i++;
        }
        return -1;
        
    }
};