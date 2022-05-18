// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
public:
    void solve(int i,string ip,string op,vector<string>&res){
        if(i==ip.size())
        {
            if(op[op.size()-1]!=' ')
            res.push_back(op);
            return;
        }
        string op1 = op;
        string op2 = op;
        op1+=ip[i];
        op2+=ip[i];
        op2+=' ';
        solve(i+1,ip,op1,res);
        solve(i+1,ip,op2,res);
        
    }
    vector<string> permutation(string S){
        // Code Here
        vector<string>res;
        string str = "";
        // str+=S[0];
        solve(0,S,str,res);
        sort(res.begin(),res.end());
        return res;
    }
};

// { Driver Code Starts.

int  main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        vector<string> ans;
        Solution obj;
        ans = obj.permutation(S);
        for(int i=0;i<ans.size();i++){
            cout<<"("<<ans[i]<<")";
        }
        cout << endl;
    }
}
  // } Driver Code Ends