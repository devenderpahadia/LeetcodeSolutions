class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        unordered_map<int,int>mp;
        vector<int>res;
        for(auto it : nums)
        {
            mp[it]++;
        }
        
        for(auto it : mp)
        {
            if(it.second==1)
            {
                if(mp.find(it.first+1)==mp.end() && mp.find(it.first-1)==mp.end())
                {
                    res.push_back(it.first);
                }
            }
        }
        return res;
    }
};