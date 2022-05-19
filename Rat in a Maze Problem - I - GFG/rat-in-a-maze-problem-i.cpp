// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    
    void solve(int i,int j,string str,vector<vector<int>> &m,vector<string> &res, int n){
        if(i==n-1 && j==n-1 && m[i][j]==1){
            res.push_back(str);
            return;
        }
        if(i<0 || j<0 || i>=n || j>=n || m[i][j]==0) return;
        m[i][j] = 0;
        solve(i+1,j,str+'D',m,res,n);
        solve(i-1,j,str+'U',m,res,n);
        solve(i,j+1,str+'R',m,res,n);
        solve(i,j-1,str+'L',m,res,n);
        m[i][j] = 1;
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string>res;
        solve(0,0,"",m,res,n);
        return res;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends