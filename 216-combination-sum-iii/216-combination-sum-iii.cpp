class Solution {
public:
    
    void solve(int i,int sum,int k,int n,vector<int>vec,vector<vector<int>>&res)
    {
        if(vec.size()==k && sum==n)
        {
            res.push_back(vec);
            return;
        }
        
        if(sum>=n)
            return;
        
        if(vec.size()>=k)
            return;
        
        for(int j=i+1;j<=9;j++)
        {
            vec.push_back(j);
            solve(j,sum+j,k,n,vec,res);
            vec.pop_back();
        }
        
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>res;
        for(int i=1;i<=9;i++)
        {
            vector<int>vec;
            vec.push_back(i);
            solve(i,i,k,n,vec,res);
        }
        return res;
    }
};