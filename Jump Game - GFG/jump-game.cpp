// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    unordered_map<int,bool>mp;
    
    bool solve(int i,int A[],int N){
        if(i==N) return true;
        
        if(A[i]==0) return false;
        
        for(int j=1;j<=A[i];j++){
            if(i+j<=N && solve(i+j,A,N)) return true;
        }
        
        return false;
    }
    
    int canReach(int A[], int N) {
        // code here
         int maxreach=A[0];
       int prevmaxreach=A[0];
       for(int i=1;i<N;i++)
       {
           if(maxreach<i)
           {
               return 0;
           }
           maxreach=max(maxreach,A[i]+i);
           if(i==prevmaxreach)
           {
               prevmaxreach=maxreach;
           }
       }
       return 1;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        int A[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];

        Solution ob;
        cout << ob.canReach(A,N) << endl;
    }
    return 0;
}  // } Driver Code Ends