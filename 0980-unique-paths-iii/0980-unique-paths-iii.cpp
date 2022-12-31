class Solution {
public:
    int res=0,empty=1;
    
    void dfs(vector<vector<int>>&grid,int i,int j,int ctr)
    {
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]==-1)
            return ;
        
        if(grid[i][j]==2)
        {
            if(ctr==empty) res++;
            return ;
        }
        grid[i][j]=-1;
        
        dfs(grid,i+1,j,ctr+1);
        dfs(grid,i,j+1,ctr+1);
        dfs(grid,i-1,j,ctr+1);
        dfs(grid,i,j-1,ctr+1);
        
        grid[i][j]=0;
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        int start,end;
        
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1)
                {
                    start=i;
                    end=j;
                }
                else if(grid[i][j]==0)
                {
                    empty++;
                }
            }
        }
        
        dfs(grid,start,end,0);
        return res;
    }
};