class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<pair<char,int>>st;
        unordered_set<int>st1;
        
        for(int i=0;i<s.size();i++)
        {
            if(st.size()==0 && s[i]==')')
            {
                st.push({s[i],i});
                continue;
            }
            if(s[i]=='(')
            {
                st.push({s[i],i});
                continue;
            }
            
            if(s[i]==')' && st.top().first=='(')
            {
                st.pop();
                continue;
            }
            
            if(s[i]==')')
            {
                st.push({s[i],i});
                continue;
            }
        }
        
        while(!st.empty())
        {
            st1.insert(st.top().second);
            st.pop();
        }
        
        string res="";
        for(int i=0;i<s.size();i++)
        {
            if(st1.find(i)==st1.end())
            {
                res+=s[i];
            }
        }
        return res;
        
    }
};
