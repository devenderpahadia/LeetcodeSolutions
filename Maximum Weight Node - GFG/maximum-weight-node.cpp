//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
  public:
  int maxWeightCell(int n, vector<int> edges)
  {
      // code here
      int mxweight = 0, mxweightCell = 0;
      vector<int>weights(n);
      for(int i = 0; i < n; i++){
          if(edges[i] == -1)
            continue;
            
          weights[edges[i]] += i;
          if(weights[edges[i]] > mxweight){
              mxweight = weights[edges[i]];
              mxweightCell = edges[i];
          }
          else if(weights[edges[i]] == mxweight && edges[i] > mxweightCell)
              mxweightCell = edges[i];
      }
      return mxweightCell;  
  }
};

//{ Driver Code Starts.
int main(){
   int tc;
   cin >> tc;
   while(tc--){
      int N;
      cin >> N;
      vector<int> Edge(N);
      for(int i=0;i<N;i++){
        cin>>Edge[i];
      }
      Solution obj;
      int ans=obj.maxWeightCell(N, Edge);
      cout<<ans<<endl;
   }
   return 0;
}
// } Driver Code Ends