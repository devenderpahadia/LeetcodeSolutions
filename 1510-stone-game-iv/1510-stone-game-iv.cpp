class Solution {
public:
    bool solve(int n,vector<int>&dp)
    {
        if(n==0)
        {
            return false;
        }
        if(dp[n]!=-1)
        {
            return dp[n];
        }
        bool res = false;
        for(int i=1;i*i<=n;i++)
        {
            if(!solve(n - i*i,dp))
            {
                res=true;
                break;
            }
        }
        return dp[n] = res;
            
    }
    bool winnerSquareGame(int n) {
        vector<int>dp(n+1,-1);
        return solve(n,dp);
    }
};
