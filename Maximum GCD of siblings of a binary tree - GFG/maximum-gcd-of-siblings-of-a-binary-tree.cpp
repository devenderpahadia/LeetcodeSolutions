// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int maxBinTreeGCD(vector<vector<int>> arr, int N) {
        // code here
        if(N <= 2) return (0);
       sort(arr.begin(),arr.end());
       int ans = 0;
       for(int i = 0; i < arr.size()-1; i++){
           if(arr[i][0] == arr[i+1][0]){
               ans = max(ans,__gcd(arr[i][1],arr[i+1][1]));
           }
       }
       return (ans);
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,u,v;
        cin>>N;
        
        vector<vector<int>> arr;
        
        for(int i=0; i<N-1; i++)
        {
            cin>>u>>v;
            vector<int> edge;
            edge.push_back(u);
            edge.push_back(v);
            arr.push_back(edge);
        }

        Solution ob;
        cout << ob.maxBinTreeGCD(arr,N) << endl;
    }
    return 0;
}  // } Driver Code Ends