class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int mn = INT_MAX;
        int m=grid.size();
        int n=grid[0].size();
        if(grid[0][0]==1 || grid[m-1][n-1]==1)
        {
            return -1;
        }
        queue<pair<int,int>>q;
        q.push({0,0});
        grid[0][0]=2;
        int k=1;
        while(!q.empty())
        {
            int sz = q.size();
            while(sz--)
            {
                pair<int,int>temp = q.front();
                q.pop();
                int i=temp.first;
                int j=temp.second;
                grid[i][j]=2;
                if(i==m-1 && j==n-1)
                {
                    return k;
                }
                if(i-1>=0 && j-1>=0 && grid[i-1][j-1]==0)
                {
                    q.push({i-1,j-1});
                    grid[i-1][j-1]=2;
                }
                if(i-1>=0 && grid[i-1][j]==0)
                {
                    q.push({i-1,j});
                    grid[i-1][j]=2;
                }
                if(i-1>=0 && j+1<n && grid[i-1][j+1]==0)
                {
                    q.push({i-1,j+1});
                    grid[i-1][j+1]=2;
                }
                if(j+1<n && grid[i][j+1]==0)
                {
                    q.push({i,j+1});
                    grid[i][j+1]=2;
                }
                if(i+1<m && j+1<n && grid[i+1][j+1]==0)
                {
                    q.push({i+1,j+1});
                    grid[i+1][j+1]=2;
                }
                if(i+1<m && grid[i+1][j]==0)
                {
                    q.push({i+1,j});
                    grid[i+1][j]=2;
                }
                if(i+1<m && j-1>=0 && grid[i+1][j-1]==0)
                {
                    q.push({i+1,j-1});
                    grid[i+1][j-1]=2;
                }
                if(j-1>=0 && grid[i][j-1]==0)
                {
                    q.push({i,j-1});
                    grid[i][j-1]=2;
                }
            }
            k++;
        }
        return -1;
    }
};