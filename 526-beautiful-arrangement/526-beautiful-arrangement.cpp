class Solution {
public:
    
    void solve(int ip,int op,vector<int>H,int&st)
    {
        if(op==ip)
        {
            st++;
            return;
        }
        
        for(int i=1;i<=ip;i++)
        {
            if(H[i]==0)
            {
                if((op+1)%i==0 || i%(op+1)==0)
                {
                    H[i]=1;
                    // op.push_back(i);
                    solve(ip,op+1,H,st);
                    // op.pop_back();
                    H[i]=0;
                }
            }
        }
        
    }
    
    int countArrangement(int n) {
        // vector<int>nums(n+1);
        // for(int i=1;i<=n;i++)
        //     nums[i]=i;
        int st=0;
        
        for(int i=1;i<=n;i++)
        {
            vector<int>H(n+1);
            H[i]=1;
            // vector<int>op;
            // op.push_back(i);
            solve(n,1,H,st);
        }
        
        return st;
    }
};