class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto it : nums)
        {
            if(mp.find(it)!=mp.end())
                return it;
            mp[it]++;
        }
        return 0;
    }
};