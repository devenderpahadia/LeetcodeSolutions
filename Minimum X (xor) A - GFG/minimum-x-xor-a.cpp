// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minVal(int a, int b) {
        // code here
        
        int ctr = 0;
        for(int i=31;i>=0;i--){
            if(b>>i & 1) ctr++;
        }
        int sum = 0;
        int i=31;
        for(;i>=0 && ctr;i--){
            if(a>>i & 1){
                sum+=(1<<i);
                ctr--;
            }
        }
        int x = sum;
        i=0;
        while(ctr){
            if(x%2==0){
                sum+=(1<<i);
                ctr--;
            }
            x/=2;
            i++;
        }
        return sum;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;

        Solution ob;
        cout << ob.minVal(a, b);

        cout << "\n";
    }

    return 0;
}  // } Driver Code Ends