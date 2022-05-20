class Solution {
public:
    void solve(int col,vector<string>mat,vector<int>lrow,vector<int>ldiag,vector<int>udiag,vector<vector<string>>&res){
        
        if(col==mat.size()){
            res.push_back(mat);
            return;
        }
        for(int row=0;row<mat.size();row++){
            if(lrow[row]==0 && ldiag[row+col]==0 && udiag[mat.size()-1 + (col-row)]==0){
                mat[row][col] = 'Q';
                lrow[row]=1;
                ldiag[row+col]=1;
                udiag[mat.size()-1 + (col-row)]=1;
                solve(col+1,mat,lrow,ldiag,udiag,res);
                mat[row][col] = '.';
                lrow[row]=0;
                ldiag[row+col]=0;
                udiag[mat.size()-1 + (col-row)]=0;
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>res;
        vector<string>mat(n,string(n,'.'));
        vector<int>lrow(n,0);
        vector<int>ldiag(2*n-1,0);
        vector<int>udiag(2*n-1,0);
        solve(0,mat,lrow,ldiag,udiag,res);
        
        return res;
    }
};