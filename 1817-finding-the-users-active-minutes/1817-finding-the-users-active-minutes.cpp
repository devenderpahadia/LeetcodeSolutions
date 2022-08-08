class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        
        unordered_map<int,set<int>>mp;
        for(auto it : logs){
            mp[it[0]].insert(it[1]);
        }
        vector<int>res(k);
        for(auto it : mp){
            res[it.second.size() - 1]++;
        }
        return res;
    }
};