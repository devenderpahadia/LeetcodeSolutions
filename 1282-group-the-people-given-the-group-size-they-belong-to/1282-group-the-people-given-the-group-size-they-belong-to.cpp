class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>&nums) {
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]].push_back(i);
        }
        vector<vector<int>>res;
        for(auto it : mp){
            vector<int>t;
            for(auto i : it.second){
                t.push_back(i);
                if(t.size()==it.first){
                    res.push_back(t);
                    t.clear();
                }
            }
            if(t.size()!=0)
            res.push_back(t);
        }
        return res;
    }
};