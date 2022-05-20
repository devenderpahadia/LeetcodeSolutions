class Solution {
public:
    
    void solve(int start,string str,string& s,vector<string>&res,unordered_set<string>&st){
        if(start==s.size()){
            str.pop_back();
            res.push_back(str);
            return;
        }
        for(int i=start;i<s.size();i++){
            string temp = s.substr(start,i-start+1);
            if(st.find(temp)!=st.end()){
                temp+=' ';
                // cout<<temp<<endl;
                solve(i+1,str+temp,s,res,st);
            }
        }
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>st;
        for(auto it : wordDict){
            st.insert(it);
        }
        vector<string>res;
        solve(0,"",s,res,st);
        return res;
    }
};