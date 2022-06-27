// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
	
	int rank[10001];
	int par[10001];
	
	
	int find(int node){
	    if(node == par[node]) return node;
	    return par[node]=find(par[node]);
	}
	
	void union1(int u,int v){
	    u = find(u);
	    v = find(v);
	    
	    if(rank[u]>rank[v]){
	        par[v] = u;
	    }
	    else if(rank[v]>rank[u]){
	        par[u] = v;
	    }
	    else{
	        par[v] = u;
	        rank[u]++;
	    }
	    
	}
	
	
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>minh;
        
        for(int i=0;i<V;i++){
            for(auto it : adj[i]){
                minh.push({it[1],{i,it[0]}});
            }
        }
        
        memset(rank,0,sizeof rank);
        for(int i=0;i<V;i++){
            par[i]=i;
        }
        int sum = 0;
        while(!minh.empty()){
            int u = minh.top().second.first;
            int v = minh.top().second.second;
            int d = minh.top().first;
            minh.pop();
            if(find(u)!=find(v)){
                union1(u,v);
                sum+=d;
            }
            
        }
        return sum;
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends