// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    int dp[101][101];
    
    int solve(int i,int j,int x,vector<vector<int>>& mat){
        if(i<0 || j<0 || i>=mat.size() || j>=mat[0].size() || mat[i][j]<=x) return 0;
        
        if(dp[i][j]!=-1)
        return dp[i][j];
        
        return dp[i][j] = max({1+solve(i+1,j,mat[i][j],mat),
                               1+solve(i,j+1,mat[i][j],mat),
                               1+solve(i-1,j,mat[i][j],mat),
                               1+solve(i,j-1,mat[i][j],mat)});
        
        
    }
    int longestIncreasingPath(vector<vector<int>>& mat) {
        // Code here
        memset(dp,-1,sizeof dp);
        
        int res = 0;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[i].size();j++){
                res = max(res,solve(i,j,0,mat));
            }
        }
        return res;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>matrix(n, vector<int>(m, 0));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)cin >> matrix[i][j];
		Solution obj;
		int ans = obj.longestIncreasingPath(matrix);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends