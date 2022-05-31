class Solution {
public:
    bool hasAllCodes(string s, int k) {
        
        if(k>s.size()) return false;
        
        int total = 1<<k;
        unordered_set<string>st;
        for(int i=0;i<s.size()-k+1;i++){
            st.insert(s.substr(i,k));
        }
        return st.size()==total;
    }
};