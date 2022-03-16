class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char>st;
        for(auto it : s)
        {
            if(st.size()==0 && it==')' )
            {
                st.push(it);
                continue;
            }
            if(it=='(')
            {
                st.push(it);
                continue;
            }
            if(it==')')
            {
                if(st.top()=='('){
                    st.pop();
                    continue;
                }
                st.push(')');
            }
        }
        return st.size();
    }
};