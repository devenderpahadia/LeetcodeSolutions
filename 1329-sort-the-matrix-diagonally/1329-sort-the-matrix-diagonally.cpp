class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        for(int i=m-1;i>=0;i--){
            int x = i;
            int y = 0;
            vector<int>temp;
            while(x<m && y<n){
                temp.push_back(mat[x][y]);
                x++;
                y++;
            }
            sort(temp.begin(),temp.end());
            x = i;
            y = 0;
            int k = 0;
            while(x<m && y<n){
                mat[x][y] = temp[k++];
                x++;
                y++;
            }
        }
        
        for(int j=1;j<n;j++){
            int x = 0;
            int y = j;
            vector<int>temp;
            while(x<m && y<n){
                temp.push_back(mat[x][y]);
                x++;
                y++;
            }
            sort(temp.begin(),temp.end());
            x = 0;
            y = j;
            int k = 0;
            while(x<m && y<n){
                mat[x][y] = temp[k++];
                x++;
                y++;
            }
        }
        return mat;
    }
};