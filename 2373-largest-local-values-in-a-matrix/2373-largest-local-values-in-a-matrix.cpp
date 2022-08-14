class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        vector<vector<int>>res;
        int n = grid.size();
        for(int i=0;i<n-2;i++){
            vector<int>temp;
            for(int j=0;j<n-2;j++){
                int x = -1;
                for(int k=i;k<i+3;k++){
                    for(int l=j;l<j+3;l++){
                        x = max(x,grid[k][l]);
                    }
                }
                temp.push_back(x);
            }
            res.push_back(temp);
        }
        return res;
    }
};