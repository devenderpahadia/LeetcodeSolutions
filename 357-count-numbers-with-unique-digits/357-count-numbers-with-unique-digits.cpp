class Solution {
public:
    
    void solve(int d,int n,vector<int>H,int& ctr)
    {
        if(d<=n)
            ctr++;
        
        if(d>=n)
            return;
        for(int j=0;j<=9;j++)
        {
            if(H[j]!=1)
            {
                H[j]=1;
                solve(d+1,n,H,ctr);
                H[j]=0;
            }
        }
    }
    
    int countNumbersWithUniqueDigits(int n) { 
        int ctr=1;
        for(int i=1;i<=9;i++)
        {
            vector<int>H(10,0);
            H[i]=1;
            solve(1,n,H,ctr);
        }
        return ctr;
    }
};