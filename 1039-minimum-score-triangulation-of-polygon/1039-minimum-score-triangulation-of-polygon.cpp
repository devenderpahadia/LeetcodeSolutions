class Solution {
public:
    int dp[51][51];
    int solve(int i,int j,vector<int>&values){
        if(i==j) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int mn = INT_MAX;
        for(int k=i;k<j;k++){
            mn = min(mn,values[i-1]*values[k]*values[j] + solve(i,k,values) + solve(k+1,j,values));
        }
        return dp[i][j] = mn;
    }
    
    int minScoreTriangulation(vector<int>& values) {
        memset(dp,-1,sizeof dp);
        return solve(1,values.size()-1,values);
    }
};