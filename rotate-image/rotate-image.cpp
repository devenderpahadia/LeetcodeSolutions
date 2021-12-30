class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int j=0;j<matrix[0].size();j++)
        {
            for(int i=0;i<matrix.size()/2;i++)
            {
                swap(matrix[i][j],matrix[n-i-1][j]);
            }
        }
        
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[i].size();j++)
            {
                if(i<j)
                {
                    swap(matrix[i][j],matrix[j][i]);
                }
            }
        }
    }
};