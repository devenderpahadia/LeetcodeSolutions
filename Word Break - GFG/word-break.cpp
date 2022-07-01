// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{
public:

    bool check(string str,vector<string>&B){
        for(auto it : B) if(str==it) return true;
        return false;
    }
    bool solve(int i,string A,vector<string>&B,int&ctr){
        
        if(i==A.size()){
            ctr++;
            return 1;
            
        }
        
        for(int j=i;j<A.size();j++){
            string s = A.substr(i,j-i+1);
            if(check(s,B)){
                if(solve(j+1,A,B,ctr)) return 1;
            }
        }
        return 0;
    }
    
    
    int wordBreak(string A, vector<string> &B) {
        //code here
        int ctr=0;
        if(solve(0,A,B,ctr)) return ctr;
        return ctr;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}
  // } Driver Code Ends