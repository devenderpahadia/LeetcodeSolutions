class Solution {
public:
    
    string solve(string s)
    {
        char c = '1';
        s[s.size()-1] = '0';
        for(int i=s.size()-2;i>=0;i--)
        {
            if(s[i]=='0')
            {
                s[i]='1';
                c = '0';
                break;
            }
            else
            {
                s[i]='0';
                c = '1';
            }
        }
        if(c=='1')
            s='1'+s;
        
        return s;
    }
    
    int numSteps(string s) {
        int ctr=0;
        while(s!="1")
        {
            if(s[s.size()-1]=='0')
            {
                ctr++;
                s.erase(s.begin()+s.size()-1);
            }
            else
            {
                s = solve(s);
                ctr++;
            }
        }
        return ctr;
    }
};