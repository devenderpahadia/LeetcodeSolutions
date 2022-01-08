class Solution {
public:
    
    int solve(int i1,int j1,int j2,vector<vector<int>>& grid,vector<vector<vector<int>>>&dp)
    {
        if(i1>=grid.size() ||  j1<0 || j1>=grid[0].size() || j2<0 || j2>=grid[0].size())
        {
            return 0;
        }
        
        if(dp[i1][j1][j2] != -1)
        {
            return dp[i1][j1][j2];
        }
        int ans = 0;
        ans+=grid[i1][j1];
        if(j1!=j2)
        {
            ans+=grid[i1][j2];
        }
        
        if(i1!=grid.size()-1)
        {
            int mx = 0;
            for(int p = j1-1; p<=j1+1;p++)
            {
                for(int q = j2-1;q<=j2+1;q++)
                {
                    mx = max(mx,solve(i1+1,p,q,grid,dp));
                }
            }
            ans+=mx;
        }
        return dp[i1][j1][j2] = ans;
        
    }
    
    
    int cherryPickup(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, -1)));
        return solve(0,0,c-1,grid,dp);
    }
};