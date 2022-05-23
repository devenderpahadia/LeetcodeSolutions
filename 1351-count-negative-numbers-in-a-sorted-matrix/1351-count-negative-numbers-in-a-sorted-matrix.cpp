class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int i=0,j=n-1;
        int ctr = 0;
        while(i<m && j>=0){
            if(grid[i][j]<0){
                // cout<<i<<" "<<j<<endl;
                ctr+=(m-i);
                // ctr--;
                j--;
            }
            else i++;
        }
        return ctr;
    }
};