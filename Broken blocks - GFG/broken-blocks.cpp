// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
int MaxGold(vector<vector<int>>&matrix){
    // Code here
    int m = matrix.size();
    int n = matrix[0].size();
    vector<vector<int>>dp(m,vector<int>(n));
    dp[0] = matrix[0];
    int res = 0;
    for(auto it : dp[0])
    {
        res = max(res,it);
    }
    for(int i=1;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            int mx = -1;
            if(j-1>=0 && dp[i-1][j-1]!=-1 && matrix[i][j]!=-1)
            {
                mx = max(mx,matrix[i][j]+dp[i-1][j-1]);
            }
            // cout<<mx<<" ";
            if(dp[i-1][j]!=-1 && matrix[i][j]!=-1)
            {
                mx = max(mx,matrix[i][j]+dp[i-1][j]);
            }
            // cout<<mx<<" ";
            if(j+1<n && dp[i-1][j+1]!=-1 && matrix[i][j]!=-1)
            {
                mx = max(mx,matrix[i][j]+dp[i-1][j+1]);
            }
            // cout<<mx<<endl;
            dp[i][j] = mx;
            res = max(res,dp[i][j]);
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
		int m, n;
		cin >> m >> n;
		vector<vector<int>>matrix(m, vector<int>(n, 0));
		for(int i = 0; i < m; i++){
			for(int j = 0; j < n; j++)
				cin >> matrix[i][j];
		}
		Solution obj;
		int ans = obj.MaxGold(matrix);
		cout << ans <<'\n';
	}
	return 0;
}  // } Driver Code Ends