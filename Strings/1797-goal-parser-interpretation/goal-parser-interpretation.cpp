class Solution {
public:
    string interpret(string command)
    {
        string s="";
        int m=command.size();
        for(int i=0;i<m;)
        {
            if(command[i] == 'G')
            {
                s+='G';
                i++;
            }
            else if((command[i]=='(') and (command[i+1]==')'))
            {
                s+='o';
                i=i+2;
            }
            else{
                i=i+4;
                s+='a';
                s+='l';
            }
        }
        return s;
        
    }
};