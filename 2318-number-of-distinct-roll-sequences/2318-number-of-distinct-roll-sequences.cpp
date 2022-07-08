class Solution {
public:
    int dp[10001][7][7];
    int mod = 1000000007;
    int solve(int i,int n,int l,int ll){
        if(i==n) return 1;
        int ctr=0;
        
        if(dp[i][l][ll]!=-1) return dp[i][l][ll];
        
        for(int j=1;j<=6;j++){
            if((l==0) || (j!=l && (j!=ll) && __gcd(l,j)==1)){
                ctr= (ctr%mod + solve(i+1,n,j,l)%mod)%mod;
                ctr%=mod;
            }
        }
        return dp[i][l][ll] = ctr;
    }
    
    int distinctSequences(int n) {
        memset(dp,-1,sizeof dp);
        return solve(0,n,0,0);
    }
};