class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        
        int ctr=0;
        unordered_map<int,int>mp;
        
        for(auto it : nums4)
            for(auto i : nums3)
            {
                mp[it+i]++;
            }
        
        for(auto it : nums1)
        {
            for(auto i : nums2)
            {
                ctr+=(mp[-(it+i)]);
            }
        }
        return ctr;
    }
};