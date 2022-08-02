class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        priority_queue<int>maxh;
        for(int i = 0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                maxh.push(mat[i][j]);
                if(maxh.size()>k) maxh.pop();
            }
        }
        return maxh.top();
    }
};