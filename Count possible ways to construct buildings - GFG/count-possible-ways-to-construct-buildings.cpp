// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	long long mod = 1000000007;
	int TotalWays(int N)
	{
	    // Code here
	    vector<long long>vec(N+1);
	    vec[1]=2;
	    vec[2]=3;
	    for(int i=3;i<=N;i++){
	        vec[i] = (vec[i-1]+vec[i-2])%mod;
	    }
	    return (vec[N]*vec[N])%mod;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution ob;
		int ans = ob.TotalWays(N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends