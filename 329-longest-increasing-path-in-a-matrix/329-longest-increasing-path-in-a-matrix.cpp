class Solution {
public:
    int dp[201][201];
    int solve(int i,int j,vector<vector<int>>&mat){
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int x = mat[i][j];
        int temp = 0;
        if(i-1>=0 && mat[i-1][j] > x){
            temp = max(temp,1+solve(i-1,j,mat));
        }
        if(j-1>=0 && mat[i][j-1] > x){
            temp = max(temp,1+solve(i,j-1,mat));
        }
        if(i+1<mat.size() && mat[i+1][j] > x){
            temp = max(temp,1+solve(i+1,j,mat));
        }
        if(j+1<mat[0].size() && mat[i][j+1] > x){
            temp = max(temp,1+solve(i,j+1,mat));
        }
        return dp[i][j] =temp;
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        memset(dp,-1,sizeof dp);
        int mx = 1;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                mx = max(mx,1+solve(i,j,matrix));
            }
        }
        return mx;
    }
};