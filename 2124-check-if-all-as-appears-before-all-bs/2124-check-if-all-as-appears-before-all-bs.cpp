class Solution {
public:
    bool checkString(string s) {
        vector<int>a;
        int b=-1;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='b')
            {
                b=i;
                break;
            }
        }
        if(b==-1)
            return true;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='a')
            {
                a.push_back(i);
            }
        }
        
        for(auto it : a)
        {
            if(it>b)
                return false;
        }
        return true;
    }
};