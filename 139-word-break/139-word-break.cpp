class Solution {
public:
    bool solve(int start,string s,unordered_set<string>&st,vector<bool>&dp){
        if(start==s.size()){
            return true;
        }
        for(int i=start;i<s.size();i++){
            string temp = s.substr(start,i-start+1);
            // cout<<temp<<endl;
            if(st.find(temp)!=st.end() && dp[i+1]){
                // cout<<temp<<endl;
                if(solve(i+1,s,st,dp)) return true;
                else dp[i+1] = false;
            }
        }
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>st;
        int n = s.size();
        vector<bool>dp(n+1,true);
        for(auto it : wordDict){
            st.insert(it);
        }
        for(int i=0;i<s.size();i++){
            string temp = s.substr(0,i+1);
            if(st.find(temp)!=st.end() && dp[i+1]){
                // cout<<temp<<endl;
                if(solve(i+1,s,st,dp)) return true;
                else
                    dp[i+1] = false;
            }
        }
        return false;
    }
};