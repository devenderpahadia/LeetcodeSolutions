// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
long long dp[81];
class Solution{
public:
    
    long long int arrangeTiles(int N){
        // code here
        if(N<=3) return 1;
        if(N==4) return 2;
        if(dp[N]!=0) return dp[N];
        return dp[N] =  (long long)((long long)arrangeTiles(N-1) + (long long)arrangeTiles(N-4));
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.arrangeTiles(N)<<"\n";
    }
    return 0;
}  // } Driver Code Ends