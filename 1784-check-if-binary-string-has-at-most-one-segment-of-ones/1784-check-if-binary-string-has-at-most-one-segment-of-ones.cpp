class Solution {
public:
    bool checkOnesSegment(string s) {
        int l=0;
        int h=s.size()-1;
        
        while(s[h]=='0')
        {
            h--;
        }
        
        for(int i=l;i<h;i++)
        {
            if(s[i]=='0')
                return false;
        }
        return true;
    }
};