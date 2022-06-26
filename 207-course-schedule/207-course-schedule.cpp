class Solution {
public:
    
    bool solve(int node,vector<int>adj[],vector<int>&vis){
        for(auto it : adj[node]){
            if(vis[it]==0){
                vis[it]=1;
                if(solve(it,adj,vis)) return 1;
            }
            else if(vis[it]==1){
                return 1;
            }
        }
        vis[node]=2;
        return 0;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& pre) {
        
        
        vector<int>adj[numCourses];
        for(auto it : pre){
            adj[it[0]].push_back(it[1]);
        }
        for(int i=0;i<numCourses;i++){
            vector<int>vis(numCourses);
            if(vis[i]==0){
                vis[i]=1;
                if(solve(i,adj,vis)) return 0;
            }
        }
        return 1;
    }
};