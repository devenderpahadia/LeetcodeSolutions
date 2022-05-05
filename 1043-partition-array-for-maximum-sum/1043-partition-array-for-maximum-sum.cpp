class Solution {
public:
    int dp[501];
    
    int solve(vector<int>&arr,int k,int i)
    {
        if(i>=arr.size())
            return 0;
        if(dp[i]!=-1)
        {
            return dp[i];
        }
        int ans = -1;
        int mx = -1;
        for(int j=i;j< min((int)arr.size(),i+k) ;j++)
        {
            mx = max(mx,arr[j]);
            ans = max(ans, mx*(j+1-i) + solve(arr,k,j+1) );
        }
        return dp[i]=ans;
    }
    
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        memset(dp,-1,sizeof dp);
        return solve(arr,k,0);
    }
};