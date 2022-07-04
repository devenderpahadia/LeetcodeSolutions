// { Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++



class Solution{
public:
    int dp[501];
    bool check(string str){
        int i=0;
        int j=str.size()-1;
        while(i<j) {if(str[i]!=str[j]) return false; i++,j--;}
        return true;
    }
    
    int solve(int i,string str){
        if(i>=str.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        
        int t = INT_MAX;
        
        for(int j=i;j<str.size();j++){
            string temp = str.substr(i,j-i+1);
            if(check(temp)){
                t = min(t,1+solve(j+1,str)) ;
            }
        }
        return dp[i]=t;
    }

    int palindromicPartition(string str)
    {
        // code here
        memset(dp,-1,sizeof dp);
        return solve(0,str)-1;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}  // } Driver Code Ends