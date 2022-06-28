// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    long long sumBetweenTwoKth( long long A[], long long N, long long K1, long long K2)
    {
        // Your code goes here
        long long sum = 0,i=0;
        priority_queue<long long>maxh1;
        priority_queue<long long>maxh2;
        for(i=0;i<N;i++){
            maxh1.push(A[i]);
            maxh2.push(A[i]);
            if(maxh1.size()>K1) maxh1.pop();
            if(maxh2.size()>K2) maxh2.pop();
        }
        maxh2.pop();
        while(maxh1.top()!=maxh2.top()){
            sum+=maxh2.top();
            maxh2.pop();
        }
        return sum;
        
    }
};

// { Driver Code Starts.
int main()
 {
    long long t;
    cin>>t;
    while(t--)
    {
        long long n, k;
        cin>>n;
        long long a[n+5];
        for(int i =0;i<n;i++)
            cin >> a[i];
        
        long long k1, k2;
        cin >> k1 >> k2;
        Solution ob;
        cout << ob.sumBetweenTwoKth(a, n, k1, k2) << endl;
        
    }
	return 0;
}
  // } Driver Code Ends