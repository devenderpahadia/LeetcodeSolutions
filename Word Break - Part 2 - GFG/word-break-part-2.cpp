// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<string> ans;
 
 void solve(string s , set<string> sete, string ch,int x){
     if(x>=s.size()){
         ans.push_back(ch);
         return;
     }
     string pre_ch=ch;;
     string c;
     for(int i=x;i<s.size();i++){
       c+=s[i];  
         
         if(sete.find(c)!=sete.end()){
             
            i==s.size()-1?ch+=c: ch+=c+" ";;
             solve(s,sete,ch,i+1);     
           ch=pre_ch;
          }
         
      }
  
}
 
 vector<string> wordBreak(int n, vector<string>& dict, string s)
    { 
        set<string> sete;
        for(auto x:dict)
            sete.insert(x);
        
        string ch="";
        solve(s,sete,ch,0);    
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        vector<string> dict;
        string s;
        cin>>n;
        for(int i = 0;i < n;i++){
            cin>>s;
            dict.push_back(s);
        }
        cin>>s;
        
        Solution ob;
        vector<string> ans = ob.wordBreak(n, dict, s);
        if(ans.size() == 0)
            cout<<"Empty\n";
        else{
            sort(ans.begin(), ans.end());
            for(int i = 0;i < ans.size();i++)
                cout<<"("<<ans[i]<<")";
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends