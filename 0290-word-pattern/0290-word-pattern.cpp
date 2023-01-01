class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string>res;
        stringstream check1(s);
        string temp;
        while(getline(check1,temp,' '))
        {
            res.push_back(temp);
        }
        unordered_map<char,string>mp;
        
        if(res.size()!=pattern.size())
            return false;
        
        for(int i=0;i<res.size();i++)
        {
            mp[pattern[i]]=res[i];
        }
        
        for(int i=0;i<pattern.size();i++)
        {
            if(mp[pattern[i]]!=res[i])
                return false;
        }
        
        unordered_map<string,char>mp1;
        for(int i=0;i<res.size();i++)
        {
            mp1[res[i]]=pattern[i];
        }
        
        for(int i=0;i<res.size();i++)
        {
            if(mp1[res[i]]!=pattern[i])
                return false;
        }
        return true;
    }
};