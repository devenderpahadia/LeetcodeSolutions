// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    vector<vector<int>> formCoils(int n) {
        
        // code here
        
        int m = 8*n*n;
        vector<int>coil1(m);
        vector<vector<int>>ans;
        
        int flag = 1;
        int steps = 2;
        
        coil1[0] = 8*n*n + 2*n;
        int curr = coil1[0];
        int idx = 1;
        
        while(idx<=m){
            for(int i = 0;i<steps;i++){
                curr = (curr - 4*n*flag);
                coil1[idx] = curr;
                idx++;
                if(idx>=m){
                    break;
                }
            }
            if(idx>=m){
                break;
            }
            for(int i=0; i<steps; i++)
            {
                curr = (curr + flag);
                coil1[idx] = curr;
                idx++;
                if(idx>=m)
                {
                    break;
                }
            }
            
            flag = flag * -1;
            steps += 2;
        }
        vector<int> coil2(m);
        for(int i=0; i<m; i++)
        {
            coil2[i] = (16*n*n) + 1 - coil1[i];
        }
        ans.push_back(coil1);
        ans.push_back(coil2);
        
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;

        Solution ob;
        vector<vector<int>> ptr = ob.formCoils(n);
        
        for(auto it: ptr)
        {
            for(int i: it)
                cout<<i<<" ";
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends