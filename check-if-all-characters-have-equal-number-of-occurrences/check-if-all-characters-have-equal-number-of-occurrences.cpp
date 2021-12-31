class Solution {
public:
    bool areOccurrencesEqual(string s) {
        unordered_map<char,int>mp;
        int mx = -1;
        for(auto it : s)
        {
            mp[it]++;
            mx = max(mx,mp[it]);
        }
        for(auto it = mp.begin();it!=mp.end();it++)
        {
            if(it->second != mx)
            {
                return false;
            }
        }
        return true;
    }
};