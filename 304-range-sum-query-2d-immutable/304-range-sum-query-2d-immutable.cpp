class NumMatrix {
public:
    vector<vector<int>>dp;
    NumMatrix(vector<vector<int>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return;
        int r=matrix.size();
        int c=matrix[0].size();
        vector<vector<int>>temp(r+1,vector<int>(c+1));
        
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                temp[i+1][j+1] = temp[i+1][j] + temp[i][j+1] + matrix[i][j] - temp[i][j];
            }
        }
        dp=temp;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return dp[row2+1][col2+1] - dp[row1][col2+1] - dp[row2+1][col1] + dp[row1][col1]; 
    }
};