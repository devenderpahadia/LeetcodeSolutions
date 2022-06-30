// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

#define mod 1000000007
class Solution{
	public:
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        int t[n+1][sum+1];
        for(int i=1;i<sum+1;i++)   t[0][i]=0;
        for(int i=0;i<n+1;i++)     t[i][0]=1;
        for(int i=1;i<n+1;i++)
        {
            for(int j=0;j<sum+1;j++)
            {
                if(arr[i-1]<=j)
                    t[i][j]=(t[i-1][j-arr[i-1]] + t[i-1][j])%mod;
                else
                    t[i][j]=t[i-1][j]%mod;
            }
        }
        return t[n][sum]%mod;
	}
	  
};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends