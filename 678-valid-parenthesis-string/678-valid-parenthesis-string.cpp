class Solution {
public:
    bool checkValidString(string s) {
        if(s.size()==0)
            return true;
        if(s.size()==1)
        {
            if(s[0]=='*')
                return true;
            
            return false;
        }
        int x=0,y=0,z=0;
        for(auto it : s)
        {
            if(it=='*') y++;
            else if(it=='(') z++;
            else x++;
            
            if(x>y+z) return false;
        }
        x=0,y=0,z=0;
        reverse(s.begin(),s.end());
        for(auto it : s)
        {
            if(it=='*') y++;
            else if(it=='(') z++;
            else x++;
            
            if(z>x+y) return false;
        }
        return true;
    }
};