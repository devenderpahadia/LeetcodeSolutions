class Solution {
public:
    unordered_map<int,vector<int>>mp;
    Solution(vector<int>& nums) {
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]].push_back(i);
        }
    }
    
    int pick(int target) {
        for(auto it : mp[target])
        {
            int x = it;
            mp[target].erase(mp[target].begin()+0);
            mp[target].push_back(x);
            return x;
        }
        return -1;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */