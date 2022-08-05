class Solution {
public:
    int dp[1001];
    int solve(vector<int>&nums,int target){
        if(target<0) return 0;
        if(target==0) return 1;
        
        if(dp[target]!=-1) return dp[target];
        
        int ctr = 0;
        
        for(int j=0;j<nums.size();j++){
            ctr+=solve(nums,target-nums[j]);
        }
        return dp[target] = ctr;
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        memset(dp,-1,sizeof dp);
        return solve(nums,target);
    }
};