class Solution {
public:
    bool isValid(string s) 
    {
        if(s.size()<2)
            return false;
        stack<char>st;
        char x,c;
        for(int i=0;i<s.size();i++)
        {
            x=s[i];
            if(x=='(' || x=='{' || x=='[')
            {
                st.push(x);
                continue;
            }
            if(st.empty()==true)
                return false;
            if(x==')')
            {
                c=st.top();
                st.pop();
                if(c!='(')
                    return false;
            }
            else if(x=='}')
            {
                c=st.top();
                st.pop();
                if(c!='{')
                    return false;
            }
            else if(x==']')
            {
                c=st.top();
                st.pop();
                if(c!='[')
                    return false;
            }
            
        }
        return st.empty();
    }
};