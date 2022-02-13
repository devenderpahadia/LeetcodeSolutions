class Solution {
public:
    
    void solve(vector<int>ip,vector<int>op,vector<vector<int>>&res)
    {
        if(ip.size()==0)
        {
            res.push_back(op);
            return;
        }
        
        vector<int>op1 = op;
        vector<int>op2 = op;
        op2.push_back(ip[0]);
        ip.erase(ip.begin()+0);
        solve(ip,op1,res);
        solve(ip,op2,res);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>res;
        vector<int>op;
        solve(nums,op,res);
        return res;
    }
};