class Solution {
public:
    void solve(vector<vector<int>>& mat)
    {
        int n=mat.size();
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n/2;j++)
            {
                swap(mat[j][i],mat[n-j-1][i]);
            }
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i<j)
                swap(mat[i][j],mat[j][i]);
            }
        }
        
        
        for(auto it : mat)
        {
            for(auto i : it)
            {
                cout<<i<<" ";
            }
            cout<<endl;
        }
    }
    
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        
        if(mat==target)
            return true;
        solve(mat);
        if(mat==target)
            return true;
        solve(mat);
        if(mat==target)
            return true;
        solve(mat);
        
        return mat==target;
    }
};