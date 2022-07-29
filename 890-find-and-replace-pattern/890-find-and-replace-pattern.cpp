class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string>res;
        
        for(auto it : words){
            unordered_map<char,char>mp;
            unordered_set<char>st;
            int i;
            for(i=0;i<it.size();i++){
                if(mp.find(pattern[i])!=mp.end()){
                    if(mp[pattern[i]]==it[i]) continue;
                    else break;
                }
                else{
                    
                    if(st.find(it[i])!=st.end()) break;
                    
                    mp[pattern[i]] = it[i];
                    st.insert(it[i]);
                }
            }
            if(i==it.size()) res.push_back(it);
        }
        return res;
    }
};