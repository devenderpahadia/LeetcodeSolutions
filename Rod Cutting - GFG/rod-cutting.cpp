// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int cutRod(int price[], int n) {
        //code here
        int t[n+1][n+1];
        vector<int>vec(n);
        for(int i=0;i<n;i++){
            vec[i] = i+1;
        }
        
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
                if(i==0 || j==0) t[i][j] = 0;
                else if(vec[i-1]<=j){
                    t[i][j] = max(t[i-1][j],price[i-1]+t[i][j-vec[i-1]]);
                }
                else t[i][j] = t[i-1][j];
            }
        }
        return t[n][n];
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}  // } Driver Code Ends