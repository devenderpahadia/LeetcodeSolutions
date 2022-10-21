//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

int mod = 100000000;
class Solution {
  public:
    int dp[100001];
    int solve(int n){
        if(n<0) return 0;
        if(n==0) return 1;
        if(dp[n]!=-1) return dp[n];
        int l = solve(n-1)%mod;
        int r = solve(n-2)%mod;
        
        return dp[n] = (l+r)%mod;
    }
    
    int fillingBucket(int N) {
        // code here
        memset(dp,-1,sizeof dp);
        return solve(N);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;

        Solution ob;
        cout << ob.fillingBucket(N) << endl;
    }
    return 0;
}
// } Driver Code Ends