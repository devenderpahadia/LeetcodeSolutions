class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int ctr=0;
        for(auto it : words)
        {
            if(it.size()<pref.size())
                continue;
            
            if(it.substr(0,pref.size())==pref)
                ctr++;
        }
        return ctr;
    }
};