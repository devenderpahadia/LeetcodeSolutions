class Solution {
public:
    int deleteAndEarn(vector<int>& nums) 
    {
        int dp[10001];
        memset(dp,0,sizeof dp);
        
        for(auto it : nums)
        {
            dp[it]+=it;
        }
        int res0 = 0;
        int res1 = 0;
        for(int i=1;i<=10000;i++)
        {
            int a = res1 + dp[i];
            int b = max(res0,res1);
            
            res0 = a;
            res1 = b;
        }
        return max(res0,res1);
    }
};