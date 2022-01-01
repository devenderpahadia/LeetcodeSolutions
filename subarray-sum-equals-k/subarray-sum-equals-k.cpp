class Solution {
public:
    int subarraySum(vector<int>& nums, int k) 
    {
        int cnt=0;
        int sum=0;
        unordered_map<int,int>mp;
        mp[0]=1;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            if(mp.find(sum-k)!=mp.end())
            {
                cnt+= mp[sum-k];
            }
            mp[sum]++;
        }
        return cnt;
    }
};