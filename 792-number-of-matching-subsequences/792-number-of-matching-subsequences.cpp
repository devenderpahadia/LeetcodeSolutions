class Solution {
public:
    bool solve(string s,string t){
        int i=0;
        int j=0;
        while(i<s.size() && j<t.size()){
            if(s[i]==t[j]) j++;
            i++;
        }
        return j==t.size();
    }
    int numMatchingSubseq(string s, vector<string>& words) {
        int ctr=0;
        unordered_map<string,bool>mp;
        for(auto it : words){
            if(mp.find(it)!=mp.end()) ctr+=(mp[it]);
            else{
                mp[it] = solve(s,it);
                ctr+=mp[it];
            }
        }
        return ctr;
    }
};