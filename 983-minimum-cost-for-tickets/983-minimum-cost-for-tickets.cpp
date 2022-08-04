class Solution {
public:
    int dp[400][400];
    int solve(int i,int d,vector<int>&days,vector<int>&costs){
        if(i==days.size()) return 0;
        
        if(dp[i][d]!=-1) return dp[i][d];
        
        if(days[i]<=d) return dp[i][d] =  solve(i+1,d,days,costs);
        
        int l = costs[0] + solve(i+1,days[i],days,costs);
        int r = costs[1] + solve(i+1,days[i]+6,days,costs);
        int s = costs[2] + solve(i+1,days[i]+29,days,costs);
        
        
        return dp[i][d] = min({l,r,s});
    }
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        memset(dp,-1,sizeof dp);
        return solve(0,0,days,costs);
    }
};