class Solution {
public:
    bool canBeValid(string s, string locked) {
        
        if(s.size()&1)
            return false;
        int x=0,y=0,z=0;
        
        for(int i=0;i<s.size();i++)
        {
            if(locked[i]=='0') y++;
            else
            {
                if(s[i]=='(') z++;
                else
                    x++;
            }
            if(x>y+z) return false;
        }
        
        x=0,y=0,z=0;
        for(int i=s.size()-1;i>=0;i--)
        {
            if(locked[i]=='0') y++;
            else
            {
                if(s[i]=='(') z++;
                else
                    x++;
            }
            if(z>x+y) return false;
        }
        
        
        return true;
    }
};