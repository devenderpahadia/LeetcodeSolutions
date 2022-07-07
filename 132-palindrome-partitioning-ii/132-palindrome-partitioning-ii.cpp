class Solution {
public:
    int dp[2005];
    bool check(string&temp,int i,int j){
        while(i<j){
            if(temp[i]!=temp[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    
    int solve(int i,string&s){
        if(i==s.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        
        int mn = INT_MAX;
        
        for(int j=i;j<s.size();j++){
            if(check(s,i,j)){
                mn = min(mn,1+solve(j+1,s));
            }
        }
        return dp[i] = mn;
    }
    
    int minCut(string&s) {
        memset(dp,-1,sizeof dp);
        return solve(0,s)-1;
    }
};