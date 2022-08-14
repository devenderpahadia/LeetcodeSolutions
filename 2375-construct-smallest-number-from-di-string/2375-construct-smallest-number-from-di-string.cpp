class Solution {
public:
    unordered_set<char>st;
    
    void solve(int i,char pre,string pat,string res,vector<string>&ans){
        if(i==pat.size()){
            ans.push_back(res);
            return;
        }
        if(pat[i]=='D' && pre=='1') return;
        for(char c='1';c<='9';c++){
            if(st.find(c)==st.end())
            {
                if((pat[i]=='D' && pre>c) || (pat[i]=='I' && pre<c))
                {
                    res.push_back(c);
                    st.insert(c);
                    solve(i+1,c,pat,res,ans);
                    st.erase(c);
                    res.pop_back();
                }
            }
        }
    }
    
    
    string smallestNumber(string pattern) {
        st.clear();
        string res="";
        vector<string>ans;
        for(char c='1';c<='9';c++){
            res.push_back(c);
            st.insert(c);
            solve(0,c,pattern,res,ans);
            st.erase(c);
            res.pop_back();
        }
        return ans[0];
    }
};