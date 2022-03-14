class Solution {
public:
    string simplifyPath(string path) {
        vector<string>st;
        stringstream checks(path);
        string s;
        while(getline(checks,s,'/'))
        {
            if(s=="." || s.size()==0) continue;
            
            if(s=="..")
            {
                if(st.size()>0)
                    st.pop_back();
            }
            else
            {
                st.push_back(s);
            }
        }
        string res="";
        for(auto f : st)
        {
            res+="/"+f;
        }
        if(res.size()==0)
            return "/";
        
        return res;
        
    }
};