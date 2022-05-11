class Solution {
public:
    
    void solve(int i,int k,int n,int &ctr)
    {
        if(k==n){
            ctr++;
            return;
        }
        for(int j=i;j<5;j++)
        {
            solve(j,k+1,n,ctr);
        }
    }
    
    int countVowelStrings(int n) {
        int ctr = 0;
        solve(0,0,n,ctr);
        return ctr;
    }
};