class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int n=prices.size();
        if(n==0)
            return 0;
        int mx = 0;
        int mn = INT_MAX;
        for(auto it : prices)
        {
            mn = min(mn,it);
            if(mn<it)
            mx = max(mx,it-mn);
        }
        return mx;
    }
};