class Solution {
public:
    void solve(int i,int n,vector<int>&res)
    {
        if(i>n)
            return;
        
        int d = i*10;
        for(int j =0;j<=9;j++)
        {
            if(d+j<=n)
                res.push_back(d+j);
            else
                break;
            solve(d+j,n,res);
        }
    }
    
    vector<int> lexicalOrder(int n) {
        vector<int>res;
        for(int i=1;i<=9;i++)
        {
            if(i<=n)
                res.push_back(i);
            else
                break;
            solve(i,n,res);
        }
        return res;
    }
};