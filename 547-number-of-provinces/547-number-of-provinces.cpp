class Solution {
public:
    void dfs(int node,vector<int>adj[],vector<int>&vis)
    {
        vis[node]=1;
        for(auto it : adj[node])
        {
            if(vis[it]!=1)
            {
                dfs(it,adj,vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<int>adj[n];
        for(int i=0;i<mat.size();i++)
        {
            for(int j=0;j<mat[0].size();j++)
            {
                if(mat[i][j]==1)
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int ctr=0;
        vector<int>vis(n,0);
        for(int i=0;i<n;i++)
        {
            if(vis[i]!=1)
            {
                ctr++;
                dfs(i,adj,vis);
            }
        }
        return ctr;
    }
};