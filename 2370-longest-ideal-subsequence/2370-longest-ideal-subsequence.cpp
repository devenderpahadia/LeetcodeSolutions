class Solution {
public:
    int dp[100010][200];
    int solve(int i,char c,string&s,int k){
        if(i==s.size()) return 0;
        
        if(dp[i][c]!=-1) return dp[i][c];
        int ctr=solve(i+1,c,s,k);
        if(c=='{'){
            ctr = max(ctr,1+solve(i+1,s[i],s,k));
        }
        else{
            if(abs(s[i]-c)<=k) ctr = max(ctr,1+solve(i+1,s[i],s,k));
        }
        return dp[i][c]=ctr;
    }
    
    int longestIdealString(string&s, int k) {
        memset(dp,-1,sizeof dp);
        return solve(0,'{',s,k);
    }
};