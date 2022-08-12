class Solution {
public:
    long long dp[100001][2];
    long long solve(int i,vector<int>&nums,bool flag){
        if(i==nums.size()) return 0;
        if(dp[i][flag]!=-1) return dp[i][flag];
        
        long long mn = INT_MIN;
        
        mn = max(mn,solve(i+1,nums,flag));
        
        if(flag){
            mn = max(mn,nums[i]+solve(i+1,nums,!flag));
        }
        else{
            mn = max(mn,-nums[i]+solve(i+1,nums,!flag));
        }
        
        return dp[i][flag] = mn;
        
    }
    
    long long maxAlternatingSum(vector<int>& nums) {
        memset(dp,-1,sizeof dp);
        return solve(0,nums,1);
    }
};