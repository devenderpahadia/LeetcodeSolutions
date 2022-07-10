// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
public:

    void solve(int i,int j,vector<vector<int>> &grid,vector<int>vec,vector<vector<int>>&res){
        if(i>=grid.size() || j>=grid[0].size()) return ;
        
        if(i==grid.size()-1 && j==grid[0].size()-1){
            vec.push_back(grid[i][j]);
            res.push_back(vec);
            return;
        }
        vec.push_back(grid[i][j]);
        solve(i+1,j,grid,vec,res);
        solve(i,j+1,grid,vec,res);
        vec.pop_back();
    }
    vector<vector<int>> findAllPossiblePaths(int n, int m, vector<vector<int>> &grid)
    {
        vector<vector<int>>res;
        solve(0,0,grid,{},res);
        return res;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        Solution ob;
        auto ans = ob.findAllPossiblePaths(n, m, grid);
        for (int i = 0; i < ans.size(); i++)
        {
            for (int j = 0; j < ans[i].size(); j++)
            {
                cout << ans[i][j] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}
  // } Driver Code Ends