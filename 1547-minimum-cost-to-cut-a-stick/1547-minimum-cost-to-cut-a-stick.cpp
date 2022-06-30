class Solution {
public:
    
    int dp[102][102];
    
    int solve(int i,int j, vector<int>& cuts){
        if(i>j) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int mn = INT_MAX;
        for(int k = i;k<=j;k++){
            mn = min(mn,cuts[j+1]-cuts[i-1] + solve(i,k-1,cuts) + solve(k+1,j,cuts));
        }
        return dp[i][j] = mn;
    }
    
    int minCost(int n, vector<int>& cuts) {
        cuts.insert(cuts.begin(),0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        memset(dp,-1,sizeof dp);
        
        return solve(1,cuts.size()-2,cuts);
    }
};