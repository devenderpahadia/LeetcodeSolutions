class Solution {
public:
    void rotate(vector<vector<int>>& mat) {
        for(int j=0;j<mat[0].size();j++)
        {
            for(int i=0;i<mat.size()/2;i++)
            {
                swap(mat[i][j],mat[mat.size()-i-1][j]);
            }
        }
        for(int i=0;i<mat.size();i++)
        {
            for(int j=0;j<mat[i].size();j++)
            {
                if(i<j)
                {
                    swap(mat[i][j],mat[j][i]);
                }
            }
        }
    }
};