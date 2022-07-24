class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char,int>mp1;
        unordered_map<char,int>mp2;
        
        for(auto it : s){
            mp1[it]++;
        }
        int ctr=0;
        for(auto it : t){
            if(mp1.find(it)!=mp1.end()){
                mp1[it]--;
                if(mp1[it]==0) mp1.erase(it);
            }
            else{
                ctr++;
            }
        }
        
        return ctr;
    }
};