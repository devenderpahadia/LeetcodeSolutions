class Solution {
public:
    int memo[4001][20];

    int util(vector<int>& nums, int target, int idx=0) {
        if(idx==nums.size() && target==0) return 1;
        if(idx==nums.size()) return 0;

        if(memo[target+2000][idx]) return memo[target+2000][idx];

        int temp=util(nums, target-nums[idx], idx+1)+util(nums, target+nums[idx], idx+1);
        return memo[target+2000][idx]=temp;
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        return util(nums, target);
    }
};