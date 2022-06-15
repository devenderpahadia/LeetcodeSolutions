bool compare(string &s1,string &s2)
{
    return s1.size() < s2.size();
}
class Solution {
public:
    int dp[10001] ;
    bool lcs(string a,string b){
        int x = a.size();
        int y = b.size();
        if(y-x != 1) return false;
        
        int i=0;
        int j=0;
        int ctr = 0;
        while(i<x && j<y){
            if(a[i]!=b[j]){
                j++;
                ctr++;
            }
            else{
                i++;
                j++;
            }
        }
        return ctr==1 || ctr==0;
    }
    
    int solve(int i,string par,int n,vector<string>& words){
        if(i==n) return 1;
        if(dp[i]!=-1) return dp[i];
        int x = 1;
        i++;
        for(;i<n;i++){
            if(lcs(par,words[i])){
                x = max(x,1+solve(i,words[i],n,words));
            }
        }
        return dp[i] = x;
    }
    
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(),words.end(),compare);
        unordered_map<string,int>mp;
        int ctr = 1;
        for(auto word : words){
            mp[word] = 1;
            for(int i=0;i<word.size();i++){
                string prev = word.substr(0,i) + word.substr(i+1);
                if(mp.find(prev)!=mp.end()){
                    mp[word] = mp[prev]+1;
                    ctr = max(ctr,mp[word]);
                }
            }
        }
        return ctr;
    }
};