// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution
{
  public:
    vector<int>res;
    int flag = 1;
    void solve(int par,int n,vector<int>adj[],vector<int>&vis){
        vis[n]=1;
        for(auto it : adj[n]){
            if(par==it){
                flag = 0;
                return;
            }
            if(!vis[it]){
                solve(n,it,adj,vis);
            }
            
        }
        res.push_back(n);
    }
    
    vector<int> findOrder(int n, int m, vector<vector<int>> pre) 
    {
        //code here
        res.clear();
        vector<int>adj[n];
        for(auto it : pre){
            adj[it[0]].push_back(it[1]);
        }
        vector<int>vis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                solve(-1,i,adj,vis);
            }
        }
        if(flag) return res;
        return {};
    }
};

// { Driver Code Starts.

int check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> prerequisites;

        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            prerequisites.push_back({u,v});
        }
        
        vector<int> adj[n];
        for (auto pre : prerequisites)
            adj[pre[1]].push_back(pre[0]);
        
        Solution obj;
        vector <int> res = obj.findOrder(n, m, prerequisites);
        if(!res.size())
            cout<<"No Ordering Possible"<<endl;
        else
            cout << check(n, res, adj) << endl;
    }
    
    return 0;
}  // } Driver Code Ends