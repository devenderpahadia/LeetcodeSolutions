class Solution {
public:
    int dp[501][501];
    
    int solve(int i,int t,vector<int>& sat){
        if(i==sat.size()){
            return 0;
        }
        if(dp[i][t]!=-1) return dp[i][t];
        int l = solve(i+1,t,sat);
        int r = (t+1)*sat[i] + solve(i+1,t+1,sat);
        
        return dp[i][t] = max(l,r);
        
    }
    
    int maxSatisfaction(vector<int>& satisfaction) {
        memset(dp,-1,sizeof dp);
        sort(satisfaction.begin(),satisfaction.end());
        return solve(0,0,satisfaction);
    }
};