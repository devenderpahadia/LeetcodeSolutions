class Solution {
public:
    bool solve(int i,vector<int>adj[],vector<int>&vis,vector<int>&res)
    {
        vis[i]=1;
        for(auto it : adj[i])
        {
            if(vis[it]==1) return true;
            else if(vis[it]==0)
            {
                if(solve(it,adj,vis,res)) return true;
            }
        }
        vis[i]=2;
        res.push_back(i);
        return false;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& pre) {
        vector<int>adj[numCourses];
        for(int i=0;i<pre.size();i++)
        {
            int u = pre[i][0];
            int v = pre[i][1];
            adj[u].push_back(v);
        }
        vector<int>vis(numCourses,0);
        vector<int>res;
        for(int i=0;i<numCourses;i++)
        {
            if(vis[i]==0)
            {
                if(solve(i,adj,vis,res)) return false;
            }
        }
        return true;
    }
};