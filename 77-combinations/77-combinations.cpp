class Solution {
public:
    void solve(vector<int>ip,vector<int>op,int index,int k,vector<vector<int>>&res)
    {
        if(op.size()==k)
        {
            res.push_back(op);
            return;
        }
        if(index>=ip.size()) return;
        int n = ip.size();
        for(int i=index;i<n;i++)
        {
            op.push_back(i+1);
            solve(ip,op,i+1,k,res);
            op.pop_back();
        }
        return;
        
    }
    vector<vector<int>> combine(int n, int k) 
    {
        
        vector<vector<int>>res;
        vector<int>ip;
        if(n<k)
            return res;
        for(int i=1;i<=n;i++)
        {
            ip.push_back(i);
        }
        vector<int>op;
        solve(ip,op,0,k,res);
        
        
        return res;
    }
};