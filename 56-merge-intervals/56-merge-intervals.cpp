class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& nums) {
        sort(nums.begin(),nums.end());
        int x = nums[0][0];
        int y = nums[0][1];
        vector<vector<int>>res;
        res.push_back({x,y});
        int j=0;
        for(int i=0;i<nums.size();i++)
        {
            if(res[j][1]>=nums[i][0])
            {
                res[j][0] = min(res[j][0],nums[i][0]);
                res[j][1] = max(res[j][1],nums[i][1]);
            }
            else
            {
                res.push_back(nums[i]);
                j++;
            }
        }
        return res;
    }
};