class Solution {
public:
    string makeGood(string s) {
        int x = 'E'-'e';
        stack<char>st;
        st.push(s[0]);
        int i=1;
        while(i<s.size()){
            if(st.size() && (s[i]-st.top() == x || s[i]-st.top() == (-1)*x)){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
            i++;
        }
        string res = "";
        while(st.size()){
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};