class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int,vector<int>>mp;
        for(auto it : edges)
        {
            mp[it[0]].push_back(it[1]);
            mp[it[1]].push_back(it[0]);
        }
        
        for(auto it = mp.begin();it!=mp.end();it++)
        {
            if(it->second.size() == edges.size())
            {
                return it->first;
            }
        }
        return 0;
    }
};