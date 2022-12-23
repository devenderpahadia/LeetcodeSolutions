int dp[5001][2];
class Solution {
public:
    int solve(vector<int>& prices,int day,bool flag)
    {
        if(day>=prices.size())
            return 0;
        
        int &ans = dp[day][flag];
        
        if(ans != -1)
            return ans;
        
        int l = solve(prices,day+1,flag);
        int r ;
        
        
        if(flag)
        {
            r = -prices[day]+solve(prices,day+1,false);   
        }
        else 
        {
            r = prices[day]+solve(prices,day+2,true);   
        }
        return ans =  max(l,r);
    }
    
    int maxProfit(vector<int>& prices) {
        memset(dp,-1,sizeof dp);
        return solve(prices,0,true);
    }
};