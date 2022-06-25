// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {

public:
    
    long long solve(int node, vector<int>adj[], int*cap,int p){
        
        long long l = 0;
        long long ctr=0;
        long long m = INT_MAX;
        for(auto it : adj[node]){
            if(it!=p){
                long long x=solve(it,adj,cap,node);
                l = max(l,x);
                m = min(m,x);
                ctr++;
            }
        }
        
        if(m == -1) return m;
        if(cap[node-1] > (long long)1e18 - ctr*l) return -1;
        return ctr*l + cap[node-1];
    }
    
    long long minimum_amount(vector<vector<int>> &Edges, int N, int S, int *Cap){
       // Code here
       vector<int>adj[N+1];
       for(auto it : Edges){
           adj[it[0]].push_back(it[1]);
           adj[it[1]].push_back(it[0]);
       }
       return solve(S,adj,Cap,S);
       
    }
};

// { Driver Code Starts.


int main()
 {
	int T;
	cin>> T;
	while (T--)
	{
	    int num, start;
	    cin>>num>>start;
	    int cap[num];
	    for(int i = 0; i<num; i++)
	        cin>>cap[i];
	    
	    vector<vector<int>> Edges(num-1);
	    for(int i=1;i < num;i++){
	        int u, v; cin >> u >> v;
	        Edges[i-1].push_back(u);
	        Edges[i-1].push_back(v);
	    }
	    
	    
    	Solution obj;
	    long long ans = obj.minimum_amount(Edges, num, start, cap);
	    cout << ans << endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends