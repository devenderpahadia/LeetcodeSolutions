class Solution {
public:
    int dp[2501][2501];
    int solve(int i,int prev,vector<int>&nums){
        if(i>=nums.size()) return 0;
        
        if(dp[i][prev+1]!=-1) return dp[i][prev+1];
        
        int l = solve(i+1,prev,nums);
        if(prev==-1 || nums[i]>nums[prev])
        {
            l = max(l,1 + solve(i+1,i,nums));
        }
        return dp[i][prev+1] = l;
    }
    
    int lengthOfLIS(vector<int>& nums) {
        memset(dp,-1,sizeof dp);
        return solve(0,-1,nums);
    }
};