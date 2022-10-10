//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  void dfs(vector<vector<int>>&grid,int n,int m,int i,int j, int delrow[],int delcol[]){
            grid[i][j]=-1;
          
          for(int z=0;z<4;z++){
               
                int nrow=i+delrow[z];
                int ncol=j+delcol[z];
                
                if( nrow>=0 && nrow<n  && ncol>=0 && ncol<m
                 && grid[nrow][ncol]==1) {
                    dfs(grid,n,m,nrow,ncol,delrow,delcol);
                 }
               
            }
    }
    
    int solve(vector<vector<int>>grid,int n,int m){
        
        int count=0;
        
        int delrow[]={-1,0,1,0};
       int delcol[]={0,1,0,-1};
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    count++;
                    dfs(grid,n,m,i,j,delrow,delcol);
                }
            }
        }
        return count;
    }
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
      vector<int>ans;
        vector<vector<int>>grid(n,vector<int>(m,0));
      for(int i=0;i<operators.size();i++){
            grid[operators[i][0]][operators[i][1]]=1;
            ans.push_back(solve(grid,n,m));
      }
      return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}

// } Driver Code Ends