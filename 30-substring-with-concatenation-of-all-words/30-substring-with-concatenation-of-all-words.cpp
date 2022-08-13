class Solution {
public:
    
    bool solve(unordered_map<string,int>mp,string s,int w){
        
        for(int i=0;i<s.size();i+=w){
            // mp[s.substr(i,w)]--;
            if(!mp[s.substr(i,w)]--) return false;
        }
        return true;
    }
    
    vector<int> findSubstring(string s, vector<string>& words) {
        
        int n = s.size();
        int tot = words.size()*words[0].size();
        int w = words[0].size();
        int i=0;
        unordered_map<string,int>mp;
        vector<int>res;
        for(auto it : words) mp[it]++;
        while(i<=n-tot){
            if(solve(mp,s.substr(i,tot),w)){
                res.push_back(i);
            }
            i++;
        }
        return res;
    }
};