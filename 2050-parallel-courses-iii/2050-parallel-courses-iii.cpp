class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<int>indeg(n+1,0);
        vector<int>adj[n+1];
        for(auto it : relations){
            indeg[it[1]]++;
            adj[it[0]].push_back(it[1]);
        }
        vector<int>vis(n+1,0);
        vector<int>end(n+1,0);
        queue<int>q;
        for(int i=1;i<=n;i++){
            if(indeg[i]==0){
                q.push(i);
                end[i] = time[i-1];
                vis[i]=1;
            }
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto it : adj[node]){
                if(vis[it]==0 && end[it]<end[node]+time[it-1])
                    end[it] = end[node]+time[it-1];
                indeg[it]--;
                if(indeg[it]==0 && vis[it]==0){
                    vis[it]=1;
                    q.push(it);
                }
            }
        }
        int mx = -1;
        for(auto it : end){
            mx = max(mx,it);
        }
        return mx;
    }
};