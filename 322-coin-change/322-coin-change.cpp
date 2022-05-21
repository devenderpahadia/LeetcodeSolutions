class Solution {
public:
    int dp[13][10001];
    int solve(int i,vector<int>& coins, int amount){
        if(amount == 0){
            return 0;
        }
        if(i<0 || amount<0){
            return 1e5;
        }
        if(dp[i][amount]!=-1) return dp[i][amount];
        return dp[i][amount]= min(1 + solve(i,coins,amount-coins[i]),solve(i-1,coins,amount));
    }
    int coinChange(vector<int>& coins, int amount) {
        memset(dp,-1,sizeof dp);
        int res = solve(coins.size()-1,coins,amount);
        return res>=1e5 ? -1:res;
    }
};