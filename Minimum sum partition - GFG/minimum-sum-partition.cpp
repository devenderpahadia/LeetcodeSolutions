// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

  public:
	int minDifference(int nums[], int n)  { 
	    // Your code goes here
	    int sum = 0;
        
        for(int i=0;i<n;i++) sum+=nums[i];
        
        bool t[n+1][sum+1];
        
        for(int i=0;i<=n;i++) t[i][0] = true;
        for(int i=1;i<=sum;i++) t[0][i] = false;
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=sum;j++){
                if(nums[i-1]<=j){
                    t[i][j] = t[i-1][j] || t[i-1][j-nums[i-1]];
                }
                else t[i][j] = t[i-1][j];
            }
        }
        
        for(int j=sum/2;j>=0;j--){
            if(t[n][j]==true)
            {
                return sum - 2*j;
            }
        }
        return 0;
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
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends