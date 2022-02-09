class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        
        int ctr=0;
        
        unordered_map<int,int>mp;
        for(auto it : nums)
        {
            mp[it]++;
        }
        for(auto it : mp)
        {
            if(k==0)
            {
                if(it.second>1)
                {
                    ctr++;
                }
            }
            else if(mp.find(it.first+k)!=mp.end())
            {
                ctr++;
            }
        }
        return ctr;
    }
};