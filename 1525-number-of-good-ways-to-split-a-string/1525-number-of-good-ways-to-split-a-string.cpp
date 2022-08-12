class Solution {
public:
    int numSplits(string s) {
        unordered_set<int>st;
        unordered_set<int>st1;
        unordered_map<int,int>mp;
        unordered_map<int,int>mp1;
        
        for(int i=0;i<s.size();i++){
            st.insert(s[i]);
            mp[i] = st.size();
        }
        
        for(int i=s.size()-1;i>=0;i--){
            st1.insert(s[i]);
            mp1[i] = st1.size();
        }
        int ctr=0;
        for(int i=0;i<s.size()-1;i++){
            if(mp[i]==mp1[i+1]) ctr++;
        }
        
        return ctr;
    }
};