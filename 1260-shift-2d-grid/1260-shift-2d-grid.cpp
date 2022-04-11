class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<int>arr;
        for(auto it : grid)
            for(auto i : it)
                arr.push_back(i);;
        
        vector<int>res = arr;
        int x = arr.size();
        for(int i=0;i<arr.size();i++)
        {
            res[(i+k)%x] = arr[i];
        }
        int y = 0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                grid[i][j] = res[y++];
            }
        }
        
        return grid;
    }
};