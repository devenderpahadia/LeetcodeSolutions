// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

int dp[201][201];
class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    
    int eggDrop(int e, int f) 
    {
        if(f<=1) return f;
        if(e==1) return f;
        
        if(dp[e][f]!=0) return dp[e][f];
        
        int mn = INT_MAX;
        for(int k = 1;k<=f;k++){
            mn =  min(mn,1+max(eggDrop(e-1,k-1),eggDrop(e,f-k)));
        }
        return dp[e][f] =  mn;
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}
  // } Driver Code Ends