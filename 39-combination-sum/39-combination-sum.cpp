class Solution {
public:
    
    void solve(vector<int>&ip, vector<int>op, int i,int sum,int t,vector<vector<int>>&res)
    {
        if(sum>t)
        {
            return;
        }
        if(sum==t)
        {
            res.push_back(op);
            return;
        }
        for(int j=i;j<ip.size();j++)
        {
            op.push_back(ip[j]);
            solve(ip,op,j,sum+ip[j],t,res);
            op.pop_back();
        }
        
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>res;
        vector<int>op;
        solve(candidates,op,0,0,target,res);
        return res;
    }
};