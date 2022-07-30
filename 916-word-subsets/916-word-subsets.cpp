class Solution {
public:
    
    bool solve(string a,string b){
        unordered_map<char,int>mp;
        unordered_map<char,int>mp1;
        for(auto it : a) mp[it]++;
        for(auto it : b) mp1[it]++;
        for(auto it : b){
            if(mp[it]<mp1[it]) return false;
        }
        return true;
        
    }
    
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        string b = "";
        unordered_map<char,int>mp;
        
        for(auto it : words2){
            unordered_map<char,int>temp;
            for(auto i : it){
                temp[i]++;
                if(temp[i]>mp[i]) mp[i] = temp[i];
            }
        }
        
        for(auto it : mp){
            while(it.second--){
                b+=it.first;
            }
        }
        
        vector<string>res;
        for(auto it : words1){
            if(solve(it,b)) res.push_back(it);
        }
        return res;
    }
};