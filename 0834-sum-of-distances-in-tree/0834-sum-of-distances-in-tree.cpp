class Solution {
public:
    vector<vector<int>> adj;
    map<pair<int,int>, pair<int,int>> mem;
    
    pair<int,int> sumDist(int node, int par=-1){
        if(mem.count({node,par}))
            return mem[{node,par}];
        
        int res = 0;
        int visits = 1;
        for(auto x: adj[node]){
            if(x == par) continue;
            auto sd = sumDist(x, node);
            res += sd.first + sd.second;
            visits += sd.second;
        }
        
        return mem[{node,par}] = {res, visits};
    }
    
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        adj = vector<vector<int>>(n);
        mem.clear();
        
        for(auto e: edges){
            int a = e[0], b = e[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            ans[i] = sumDist(i).first;
        }
        return ans;
    }
};