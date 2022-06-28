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
        int n = nums.size();
        int dp[n+1][n+1];
        memset(dp,0,sizeof dp);
        for(int i=n-1;i>=0;i--){
            for(int j=i-1;j>=-1;j--){
                int l = dp[i+1][j+1];
                if(j==-1 || nums[i]>nums[j])
                {
                    l = max(l,1 + dp[i+1][i+1]);
                }
                dp[i][j+1] = l;
            }
        }
        return dp[0][0];
    }
};