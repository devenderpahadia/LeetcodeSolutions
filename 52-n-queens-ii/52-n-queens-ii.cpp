class Solution {
public:
    bool check(int i,int j,vector<string>arr){
        for(int x = j-1;x>=0;x--){
            if(arr[i][x]=='Q') return false;
        }
        int x = i;
        int y = j;
        while(x-- && y--)
        {
            if(arr[x][y]=='Q') return false;
        }
        x = i, y = j;
        while(++x < arr.size() && y--)
        {
            if(arr[x][y]=='Q') return false;
        }
        return true;
    }
    void solve(int j,int n,vector<string>vec,vector<vector<string>>&res){
        if(j==n) {
            res.push_back(vec);
            return;
        }
        for(int i=0;i<n;i++){
            if(check(i,j,vec)){
                vec[i][j] = 'Q';
                solve(j+1,n,vec,res);
                vec[i][j] = '.';
            }
        }
    }
    int totalNQueens(int n) {
        vector<vector<string>>res;
        vector<string>vec(n,string(n,'.'));
        solve(0,n,vec,res);
        return res.size();
    }
};