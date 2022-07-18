class Solution {
public:
    
    int numSubmatrixSumTarget(vector<vector<int>>& mat, int target) {
        int res = 0;
        for(int i=0;i<mat.size();i++){
            for(int j = 1;j<mat[i].size();j++){
                mat[i][j]+=mat[i][j-1];
            }
        }
        int m = mat.size();
        int n = mat[0].size();
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                unordered_map<int,int>mp;
                mp[0]=1;
                int sum = 0;
                for(int r = 0;r<m;r++){
                    sum+=mat[r][j] - (i>0 ? mat[r][i-1]:0);
                    if(mp.find(sum-target)!=mp.end()){
                        res+=mp[sum-target];
                    }
                    mp[sum]++;
                }
            }
        }
        
        return res;
    }
};