class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int n=prices.size();
        if(n==0)
            return 0;
        int cost = 0;
        int mx = 0;
        int mn = prices[0];
        
        for(int i=0;i<n;i++)
        {
            mn = min(mn,prices[i]);
            cost = prices[i] - mn;
            mx = max(mx,cost);
        }
        return mx;
    }
};