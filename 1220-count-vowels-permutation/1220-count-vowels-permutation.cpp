#define mod 1000000007
class Solution {
public:
    int dp[20001][1000];
    int solve(int n,char c){
        if(n<=0) return 1;
        
        if(dp[n][c-'a']!=-1) return dp[n][c-'a']%mod;
        
        int ctr=0;
        if(c=='a'){
            ctr+=solve(n-1,'e');
            ctr%=mod;
        }
        if(c=='e'){
            ctr+=solve(n-1,'a');
            ctr%=mod;
            ctr+=solve(n-1,'i');
            ctr%=mod;
        }
        if(c=='i'){
            
            ctr+=solve(n-1,'a');
            ctr%=mod;
            ctr+=solve(n-1,'e');
            ctr%=mod;
            ctr+=solve(n-1,'o');
            ctr%=mod;
            ctr+=solve(n-1,'u');
            ctr%=mod;
        }
        if(c=='o'){
            ctr+=solve(n-1,'i');
            ctr%=mod;
            ctr+=solve(n-1,'u');
            ctr%=mod;
        }
        if(c=='u'){
            ctr+=solve(n-1,'a');
            ctr%=mod;
        }
        
        return  dp[n][c-'a'] = ctr%mod;;
    }
    
    int countVowelPermutation(int n) {
        memset(dp,-1,sizeof dp);
        int ctr=0;
        ctr+=solve(n-1,'a');
        ctr%=mod;
        ctr+=solve(n-1,'e');
        ctr%=mod;
        ctr+=solve(n-1,'i');
        ctr%=mod;
        ctr+=solve(n-1,'o');
        ctr%=mod;
        ctr+=solve(n-1,'u');
        ctr%=mod;
        return ctr%mod;;
    }
};