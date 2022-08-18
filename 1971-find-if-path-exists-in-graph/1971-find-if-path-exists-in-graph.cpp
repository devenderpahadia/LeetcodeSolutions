class Solution {
public:
    
    bool solve(int sr,int dest,vector<int>adj[],vector<int>&vis){
        vis[sr]=1;
        
        if(sr==dest){
            return true;
        }
        
        for(auto it : adj[sr]){
            if(vis[it]==0 && solve(it,dest,adj,vis)) return 1;
        }
        return 0;
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int>adj[n];
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int>vis(n);
        return solve(source,destination,adj,vis);
    }
};