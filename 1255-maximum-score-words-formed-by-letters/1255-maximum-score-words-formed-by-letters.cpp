class Solution {
public:
    
    void solve(int idx,vector<string>& words, vector<int>& cnt, vector<int>& score,vector<int>&used,int curr,int&res){
        for(int i=0;i<26;i++){
            if(used[i]>cnt[i]) return;
        }
        res = max(res,curr);
        for(int j=idx;j<words.size();j++){
            for(auto it : words[j]){
                used[it-'a']++;
                curr+=score[it-'a'];
            }
            solve(j+1,words,cnt,score,used,curr,res);
            for(auto it : words[j]){
                used[it-'a']--;
                curr-=score[it-'a'];
            }
        }
        
    }
    
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int>cnt(26);
        vector<int>used(26);
        for(auto it : letters){
            cnt[it-'a']++;
        }
        int res = 0;
        solve(0,words,cnt,score,used,0,res);
        return res;
    }
};