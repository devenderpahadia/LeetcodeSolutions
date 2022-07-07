class Solution {
public:
    int dp[303][303];
    int solve(int i,int j,vector<int>&values){
        if(i==j) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int mn = -2;
        for(int k=i;k<j;k++){
            mn = max(mn,values[i-1]*values[k]*values[j] + solve(i,k,values) + solve(k+1,j,values));
        }
        return dp[i][j] = mn;
    }
    
    int maxCoins(vector<int>& values) {
        values.push_back(1);
        values.insert(values.begin(),1);
        
        memset(dp,-1,sizeof dp);
        return solve(1,values.size()-1,values);
    }
};