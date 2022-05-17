// { Driver Code Starts
//Initial Template for C

#include <stdio.h>


 // } Driver Code Ends
//User function Template for C


//Function to find the minimum element in sorted and rotated array.
int minNumber(int arr[], int low, int high)
{
    // Your code here
    int res=arr[0];
    while(low<=high)
    {
        int mid = low + (high-low)/2;
        if(arr[0]<=arr[mid]) low = mid+1;
        else
        {
            res = arr[mid];
            high=mid-1;
        }
    }
    return res;
}

// { Driver Code Starts.

int main()
{
	
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n;
		scanf("%d", &n);
		int a[n];
		for(int i=0;i<n;++i)
			scanf("%d", &a[i]);	
	
		printf("%d\n", minNumber(a,0,n-1) );
	}
	return 0;
}  // } Driver Code Ends