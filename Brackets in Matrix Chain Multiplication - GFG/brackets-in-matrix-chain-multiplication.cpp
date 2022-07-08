// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int dp[27][27];
    int br[27][27];
    
    void func(int i,int j,int n,char&c,string&res){
        if(i==j){
            res+=c;
            c++;
            return;
        }
        res+='(';
        
        func(i,br[i][j],n,c,res);
        func(br[i][j]+1,j,n,c,res);
        
        res+=')';
    }
    
    int solve(int i,int j,int p[]){
        if(i>=j) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int mn = INT_MAX;
        for(int k=i;k<j;k++){
            int t = p[i-1]*p[k]*p[j] + solve(i,k,p)+solve(k+1,j,p);
            if(t<mn){
                mn = t;
                br[i][j] = k;
                
            }
        }
        return dp[i][j] = mn;
    } 
    
    string matrixChainOrder(int p[], int n){
        // code here
        memset(dp,-1,sizeof dp);
        memset(br,-1,sizeof br);
        int mn = solve(1,n-1,p);
        string res = "";
        char c = 'A';
        func(1,n-1,n,c,res);
        return res;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int p[n];
        for(int i = 0;i < n;i++)
            cin>>p[i];
        
        Solution ob;
        cout<<ob.matrixChainOrder(p, n)<<"\n";
    }
    return 0;
}  // } Driver Code Ends