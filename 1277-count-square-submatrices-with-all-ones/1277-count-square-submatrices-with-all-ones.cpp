class Solution {
public:
    int countSquares(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        vector<vector<int>>arr(m,vector<int>(n,0));
        for(int i=0;i<m;i++)
        {
            arr[i][0] = mat[i][0];
        }
        for(int i=0;i<n;i++)
        {
            arr[0][i] = mat[0][i];
        }
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                if(mat[i][j]==0)
                {
                    arr[i][j]=0;
                }
                else
                {
                    arr[i][j] = 1 + min({arr[i-1][j],arr[i][j-1],arr[i-1][j-1]});
                }
            }
        }
        int sum = 0;
        for(auto it : arr)
        {
            for(auto i : it)
            {
                sum+=i;
            }
        }
        return sum;
    }
};