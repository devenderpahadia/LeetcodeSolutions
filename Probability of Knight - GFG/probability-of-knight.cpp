// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	double dp[101][101][101];
	
	double solve(int x,int y,int n,int step)
	{
	    double ctr = 0;
	    if(x>=0 && y>=0 && x<n && y<n)
	    {
	        if(step == 0)
	        return 1;
	        if(dp[x][y][step]!=0)
	        return dp[x][y][step];
	        
	        ctr+=solve(x-2,y-1,n,step-1);
	        ctr+=solve(x-1,y+2,n,step-1);
	        ctr+=solve(x-2,y+1,n,step-1);
	        ctr+=solve(x-1,y-2,n,step-1);
	        ctr+=solve(x+1,y+2,n,step-1);
	        ctr+=solve(x+1,y-2,n,step-1);
	        ctr+=solve(x+2,y+1,n,step-1);
	        ctr+=solve(x+2,y-1,n,step-1);
	        
	        dp[x][y][step] = ctr;
	    }
	    return ctr;
	}
	
	double findProb(int N,int start_x, int start_y, int steps)
	{
	    // Code here
	    memset(dp,0,sizeof dp);
	    double count = solve(start_x,start_y,N,steps);
	   // cout<<pow(8,steps)<<endl;
	    return count/pow(8,steps);
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N, start_x, start_y, steps;
		cin >> N >> start_x >> start_y >> steps;
		Solution ob;
		double ans = ob.findProb(N, start_x, start_y, steps);
		cout << fixed << setprecision(6) << ans <<"\n";
	}  
	return 0;
}  // } Driver Code Ends