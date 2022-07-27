class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int idx = lower_bound(nums.begin(),nums.end(),target) - nums.begin();
        
        if(idx!=nums.size() && nums[idx]==target){
            int j = upper_bound(nums.begin(),nums.end(),target) - nums.begin();
            return {idx,j-1};
        }
        return {-1,-1};
    }
};