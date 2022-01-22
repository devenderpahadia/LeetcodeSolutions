class Solution {
public:
    string makeFancyString(string s) {
        char bit = s[0];
        string res="";
        int ctr=1;
        res+=s[0];
        for(int i=1;i<s.size();i++)
        {   
            if(bit==s[i])
            {
                ctr++;
            }
            else
            {
                ctr=1;
                bit=s[i];
            }
            if(ctr>=3)
            {
                ctr++;
                continue;
            }
            res+=s[i];
            
        }
        return res;
    }
};