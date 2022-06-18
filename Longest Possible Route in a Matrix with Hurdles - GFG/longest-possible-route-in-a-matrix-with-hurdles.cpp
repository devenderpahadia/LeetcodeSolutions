// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
public:
    void solve(int x,int y,int xd,int yd,int t,vector<vector<int>> mat, int &mx){
        if(x==xd && y==yd){
            mx = max(mx,t);
            return;
        }
        if(x<0 || y<0 || x>=mat.size() || y>=mat[0].size() || mat[x][y]==0) return;
        
        mat[x][y] = 0;
        // cout<<x<<" "<<y<<endl;
        solve(x+1,y,xd,yd,t+1,mat,mx);
        solve(x,y+1,xd,yd,t+1,mat,mx);
        solve(x-1,y,xd,yd,t+1,mat,mx);
        solve(x,y-1,xd,yd,t+1,mat,mx);
        
        mat[x][y] = 1;
    }

    int longestPath(vector<vector<int>> matrix, int xs, int ys, int xd, int yd)
    {
        // code here
        if(matrix[xs][ys]==0 || matrix[xd][yd]==0) return -1;
        
        int mx = -1;
        solve(xs,ys,xd,yd,0,matrix,mx);
        return mx;
        
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
        int xs, ys, xd, yd;
        cin >> xs >> ys >> xd >> yd;
        vector<vector<int>> mat(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> mat[i][j];
            }
        }
        Solution ob;
        int ans = ob.longestPath(mat, xs, ys, xd, yd);
        cout << ans;
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends