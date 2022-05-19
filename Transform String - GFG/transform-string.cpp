// { Driver Code Starts
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    int transform (string A, string B)
    {
        //code here.
        unordered_map<char,int>mp;
        for(auto it : A){
            mp[it]++;
        }
        for(auto it : B){
            mp[it]--;
            if(mp[it]==0) {
                mp.erase(it);
            }
        }
        if(mp.size()>0) return -1;
        
        int n=A.size();
        int i=n-1,j=n-1;
        int ctr=0;
        while(i>=0&&j>=0){
            if(A[i]==B[j]){
                i--;j--;
            }
            else{
                i--;
                ctr++;
            }
        }
        return ctr;
    }
};


// { Driver Code Starts.

int main () 
{
    int t; cin >> t;
    while (t--)
    {
        string A, B; 
        cin >> A >> B;
        Solution ob;
        cout <<ob.transform (A, B) << endl;
    }
}  // } Driver Code Ends