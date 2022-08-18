class Solution {
public:
    
    void solve(int n,vector<pair<int,int>>adj[],int mt,int sum,int&res,vector<int>& values){
        if(mt<0) return;
        sum+=values[n];
        if(n==0){
            res = max(res,sum);
        }
        int x = values[n];
        values[n] = 0;
        for(auto it : adj[n]){
            int node = it.first;
            int t = it.second;
            solve(node,adj,mt-t,sum,res,values);
        }
        values[n]=x;
    }
    
    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {
        int n = values.size();
        vector<pair<int,int>>adj[n];
        for(auto it : edges){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        
        int sum = 0;
        solve(0,adj,maxTime,0,sum,values);
        return sum;
    }
};