class Solution {
public:
    
    bool solve(int node,vector<int>adj[],vector<int>&color){
        for(auto it : adj[node]){
            if(color[it]==-1){
                color[it] = !color[node];
                if(!solve(it,adj,color)) return false;
            }
            else if(color[it]==color[node]) return false;
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>color(n,-1);
        vector<int>adj[n];
        for(int i=0;i<graph.size();i++){
            for(auto it : graph[i]){
                adj[i].push_back(it);
                adj[it].push_back(i);
            }
        }
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                color[i] = 0;
                if(!solve(i,adj,color)) return false;
            }
        }
        return true;
    }
};