class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int mx = INT_MAX;
        for(int i=0;i<nums.size();i++)
        {
            if(target==nums[i])
            {
                mx = min(mx,abs(i-start));
            }
        }
        return mx;
    }
};