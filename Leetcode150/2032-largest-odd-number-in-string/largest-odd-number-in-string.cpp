class Solution {
public:
    string largestOddNumber(string num)
    {
        int n = num.size()-1;
        for(int i=n;i>=0;i--)
        {
            if((num[i]-'0')%2!=0){
                n=i;
                break;
            }
            if(i==0)n=-1;
        }
       
        return (n==-1)?"": num.substr(0,n+1);
        
    }
};