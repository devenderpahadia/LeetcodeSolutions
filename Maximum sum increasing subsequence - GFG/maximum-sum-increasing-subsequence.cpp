// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
		

	public:
	
	int dp[1001][1001];
	
	int solve1(int i,int par,int arr[], int n){
	    if(i>=n) return 0;
	    
	    if(dp[i][par+1]!=-1) return dp[i][par+1];
	    
	    int l = solve1(i+1,par,arr,n);
	    
	    if(par==-1 || arr[i]>arr[par]){
	        l = max(l, arr[i]+ solve1(i+1,i,arr,n));
	    }
	    return dp[i][par+1] = l;
	}
	
	int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes here
	    memset(dp,-1,sizeof dp);
	    return solve1(0,-1,arr,n);
	}  
};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}

  // } Driver Code Ends