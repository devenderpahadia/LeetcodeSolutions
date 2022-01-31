class Solution {
public:
    string makeGood(string s) {
        
        string str="";
        stack<char>st;
        for(int i=0;i<s.size();)
        {
            if(st.empty())
            {
                st.push(s[i]);
                i++;
                continue;
            }
            else
            {
                if(s[i]>='A' && s[i]<='Z')
                {
                    if(st.top() == s[i]-'A' + 'a')
                    {
                        st.pop();
                        i++;
                        continue;
                    }
                    else
                    {
                        st.push(s[i]);
                        i++;
                        continue;
                    }
                }
                else if(s[i]>='a' && s[i]<='z')
                {
                    if(st.top() == s[i]-'a' + 'A')
                    {
                        st.pop();
                        i++;
                        continue;
                    }
                    else
                    {
                        st.push(s[i]);
                        i++;
                        continue;
                    }
                }
                else
                {
                    st.push(s[i]);
                    i++;
                    continue;
                }
            }            
        }
        while(st.size())
        {
            str+=st.top();
            st.pop();
        }
        reverse(str.begin(),str.end());
        return str;
    }
};