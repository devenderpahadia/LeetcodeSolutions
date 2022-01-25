class Solution {
public:
    bool checkRecord(string s) {
        int a = 0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='A')
                a++;
        }
        if(a>=2)
            return false;
        
        if(s.find("LLL")!= -1)
            return false;
        
        return true;
    }
};