class Solution {
public:
    int dp[101][101][101];
    
    int solve(int i,int l,int t,vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target){
        
        if(t>target) return INT_MAX/2;
        if(i==m){
            return (t==target)?0:INT_MAX/2;
        }
        
        if(dp[i][l][t]!=-1) return dp[i][l][t];
        
        int mn = INT_MAX/2;
        if(houses[i]==0){
            for(int j=0;j<n;j++){
                mn = min(mn, cost[i][j] + solve(i+1,j+1,(l==j+1)?t:t+1,houses,cost,m,n,target));
            }
        }
        else{
            mn = min(mn, solve(i+1,houses[i],(l==houses[i])?t:t+1,houses,cost,m,n,target));
        }
        return dp[i][l][t] = mn;
    }
    
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        memset(dp,-1,sizeof dp);
        int x = solve(0,0,0,houses,cost,m,n,target); 
        return x==INT_MAX/2?-1:x;
    }
};