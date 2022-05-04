class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        unordered_map<int,int>mp;
        for(auto it : nums)
        {
            mp[it]++;
        }
        int ctr=0;
        for(int i=0;i<nums.size();i++)
        {
            if(mp.find(nums[i])!=mp.end() && mp.find(k-nums[i])!=mp.end())
            {
                if(nums[i]==(k-nums[i]))
                {
                    if(mp[nums[i]]>1)
                    {
                        ctr++;
                        mp[nums[i]]--;
                        mp[nums[i]]--;
                        if(mp[nums[i]]==0)
                        {
                            mp.erase(nums[i]);
                        }
                    }
                }
                else
                {
                    ctr++;
                    mp[nums[i]]--;
                    if(mp[nums[i]]==0)
                    {
                        mp.erase(nums[i]);
                    }
                    mp[k-nums[i]]--;
                    if(mp[k-nums[i]]==0)
                    {
                        mp.erase(k-nums[i]);
                    }
                }
            }
        }
        return ctr;
    }
};