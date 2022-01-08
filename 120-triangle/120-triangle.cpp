class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int dp[n];
        for(int i=n-1;i>=0;i--)
        {
            for(int j=0;j<triangle[i].size();j++)
            {
                if(i==n-1)
                {
                    dp[j] = triangle[i][j];
                }
                else
                {
                    dp[j] = min(dp[j]+triangle[i][j],dp[j+1] + triangle[i][j]);
                }
            }
        }
        return dp[0];
    }
};