class Solution {
public:
    int dp[101][101][201];
    
    bool solve(int i,string s1,int j,string s2,int k,string s3){
        if(k==s3.size()) return true;
        
        if(dp[i][j][k]!=-1) return dp[i][j][k];
        
        
        if(i<s1.size() && j<s2.size() && s1[i]==s3[k] && s2[j]==s3[k]){
            return dp[i][j][k] =  solve(i+1,s1,j,s2,k+1,s3) || solve(i,s1,j+1,s2,k+1,s3);
        }
        if(i<s1.size() && s1[i]==s3[k]) return dp[i][j][k] = solve(i+1,s1,j,s2,k+1,s3);
        if(j<s2.size() && s2[j]==s3[k]) return dp[i][j][k] = solve(i,s1,j+1,s2,k+1,s3);
        
        return dp[i][j][k] = false;
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        memset(dp,-1,sizeof dp);
        if(s1.size()+s2.size()!=s3.size()) return false;
        return solve(0,s1,0,s2,0,s3);
    }
};