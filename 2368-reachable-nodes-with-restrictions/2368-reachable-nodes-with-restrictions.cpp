class Solution {
public:
    
    void solve(int n,vector<int>adj[],vector<int>&vis){
        vis[n]=1;
        for(auto it : adj[n]){
            if(!vis[it]){
                solve(it,adj,vis);
            }
        }
    }
    
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        unordered_set<int>st;
        for(auto it : restricted){
            st.insert(it);
        }
        vector<int>adj[n];
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            if(st.find(u)!=st.end() || st.find(v)!=st.end()) continue;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int>vis(n);
        solve(0,adj,vis);
        int ctr=0;
        for(auto it : vis){
            if(it) ctr++;
        }
        return ctr;
    }
};