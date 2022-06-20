// { Driver Code Starts
#include <iostream>
using namespace std;


 // } Driver Code Ends
class Solution{
public:
    
    void solve(int sum,int n,int x,long&res){
        if(sum==x && n==0){
            res++;
            return;
        }
        if(n<1) return;
        if(sum>x) return;
        for(int i=1;i<x;i++){
            solve(sum+i,n-1,x,res);
        }
        return;
    }
    
    long posIntSol(string s)
    {
        int n = 0;
        int i=0;
        for(auto it : s){
            if(it=='+') n++;
            if(it=='=') break;
            i++;
        }
        n++;
        i++;
        string num = s.substr(i);
        int x = stoi(num);
        long res = 0;
        solve(0,n,x,res);
        return res;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.posIntSol(s)<<endl;
    }
    return 0;
}
  // } Driver Code Ends