class Solution {
public:
    int ctr=0;
    void solve(int i,int parent,vector<int>adj[],vector<int>&low,vector<int>&tin,vector<int>&vis,int&timer,vector<vector<int>>&res){
        vis[i] = 1;
        low[i] = tin[i] = timer++;
        for(auto it : adj[i]){
            if(it==parent) continue;
            if(!vis[it])
            {
                solve(it,i,adj,low,tin,vis,timer,res);
                low[i] = min(low[i],low[it]);
                if(low[it]>tin[i]){
                    res.push_back({it,i});
                }
            }
            else low[i] = min(low[i],tin[it]);
        }
    }
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& edges) {
        vector<vector<int>>res;
        vector<int>adj[n];
        vector<int>low(n,0);
        vector<int>tin(n,0);
        vector<int>vis(n,0);
        ctr=0;
        int timer = 0;
        for(int j=0;j<edges.size();j++){
            adj[edges[j][0]].push_back(edges[j][1]);
            adj[edges[j][1]].push_back(edges[j][0]);
        }
        for(int i = 0;i<n;i++)
        {
            solve(i,-1,adj,low,tin,vis,timer,res);
        }
        return res;
    }
};
