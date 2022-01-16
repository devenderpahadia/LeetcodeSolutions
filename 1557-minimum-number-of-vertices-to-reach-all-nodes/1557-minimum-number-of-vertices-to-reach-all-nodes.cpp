class Solution {
public:
//     void solve(int i,vector<int>adj[],vector<int>&vis)
//     {
//         vis[i]=1;
//         for(auto it : adj[i])
//         {
//             if(vis[it]==0)
//             {
//                 solve(it,adj,vis);
//             }
//         }
//     }
    
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int>adj[n];
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        // vector<int>vis(n,0);
        vector<int>res;
        for(int i=0;i<n;i++)
        {
            if(adj[i].size()==0)
            {
                res.push_back(i);
            }
        }
        return res;
    }
};