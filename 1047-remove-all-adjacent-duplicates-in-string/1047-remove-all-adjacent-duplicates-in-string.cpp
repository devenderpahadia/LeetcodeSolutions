class Solution {
public:
    string removeDuplicates(string s) {
        stack<char>st;
        if(s.size()==0)
            return "";
        st.push(s[0]);
        int i=1;
        while(i<(int)s.size()){
            if(st.size() && s[i]!=st.top())
                st.push(s[i]),i++;
            else if(st.size() && s[i]==st.top())
                st.pop(),i++;
            else st.push(s[i]),i++;
        }
        string res="";
        while(st.size()>0){
            res+=(st.top());
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};