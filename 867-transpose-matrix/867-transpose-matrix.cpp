class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>>res;
        if(m!=n)
        {
            for(int i=0;i<n;i++)
            {
                vector<int>temp;
                for(int j=0;j<m;j++)
                {
                    temp.push_back(matrix[j][i]);
                }
                res.push_back(temp);
            }
            return res;
        }
        
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                if(i<j)
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        return matrix;
    }
};