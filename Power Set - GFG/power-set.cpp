// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	
	    void solve(string op,string ip,vector<string>&res){
	        if(ip.size()==0){
	            res.push_back(op);
	            return;
	        }
	        string op1 = op;
	        string op2 = op;
	        op2+=ip[0];
	        ip.erase(ip.begin()+0);
	        solve(op1,ip,res);
	        solve(op2,ip,res);
	    }
		vector<string> AllPossibleStrings(string s){
		    // Code here
		    vector<string>res;
		    solve("",s,res);
		    sort(res.begin(),res.end());
		    res.erase(res.begin()+0);
		    return res;
		}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}  // } Driver Code Ends