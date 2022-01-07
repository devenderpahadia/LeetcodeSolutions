class Solution {
public:
    void solve(int n,vector<int>op,int index,int k,vector<vector<int>>&res)
    {
        if(op.size()==k)
        {
            res.push_back(op);
            return;
        }
        if(index>n) return;
        for(int i=index;i<=n;i++)
        {
            op.push_back(i);
            solve(n,op,i+1,k,res);
            op.pop_back();
        }
        return;
        
    }
    vector<vector<int>> combine(int n, int k) 
    {
        
        vector<vector<int>>res;
        if(n<k)
            return res;
        vector<int>op;
        solve(n,op,1,k,res);
        
        
        return res;
    }
};