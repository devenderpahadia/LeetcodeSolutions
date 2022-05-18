class Solution {
public:
    
    void solve(int i,int target,vector<int>ip,vector<int>op,vector<vector<int>>&res){
        if(target==0){
            res.push_back(op);
            return;
        }
        for(int j=i;j<ip.size();j++){
            if(i!=j && ip[j-1]==ip[j]) continue;
            if(ip[j]<=target){
                op.push_back(ip[j]);
                solve(j+1,target-ip[j],ip,op,res);
                op.pop_back();
            }
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>res;
        sort(candidates.begin(),candidates.end());
        solve(0,target,candidates,{},res);
        return res;
    }
};