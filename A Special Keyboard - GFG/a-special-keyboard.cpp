// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int findTime(string S1, string S2) {
        // code here
        int l = 0;
        int ctr = 0;
        unordered_map<char,int>mp;
        for(int i=0;i<S1.size();i++){
            mp[S1[i]] = i;
        }
        
        for(int i=0;i<S2.size();i++){
            ctr+=(abs(l-mp[S2[i]]));
            l = mp[S2[i]];
        }
        return ctr;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S1,S2;
        cin>>S1;
        cin>>S2;

        Solution ob;
        cout<<ob.findTime(S1,S2)<<endl;
    }
    return 0;
}  // } Driver Code Ends