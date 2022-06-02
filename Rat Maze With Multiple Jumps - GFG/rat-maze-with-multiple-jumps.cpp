// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    bool solve(int i,int j,vector<vector<int>>&mat,vector<vector<int>>&res){
        if(i>mat.size()-1 || j>mat[0].size()-1) return false;
        res[i][j] = 1;
        if(i==mat.size()-1 && j==mat[0].size()-1){
            return true;
        }
        
        for(int x = 1;x<=mat[i][j] ; x++){
            if(solve(i,j+x,mat,res)) return true;
            if(solve(i+x,j,mat,res)) return true;
        }
        res[i][j]=0;
        return false;
    }
	vector<vector<int>> ShortestDistance(vector<vector<int>>&matrix){
	   // Code here
	   vector<vector<int>>res(matrix.size(),vector<int>(matrix.size(),0));
	   if(solve(0,0,matrix,res)) return res;
	   else return {{-1}};
	   
	}
	
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>matrix(n, vector<int>(n,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.ShortestDistance(matrix);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}  // } Driver Code Ends