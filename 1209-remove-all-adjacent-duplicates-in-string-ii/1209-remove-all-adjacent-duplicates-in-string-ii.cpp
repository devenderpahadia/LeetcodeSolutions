class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>>st;
        st.push({s[0],1});
        for(int i=1;i<s.size();i++)
        {
            if(st.size()>0 && st.top().first==s[i])
            {
                if(st.top().second+1 == k)
                {
                    int t = k-1;
                    while(t--)
                    {
                        st.pop();
                    }
                }
                else
                {
                    st.push({s[i],st.top().second+1});
                }
            }
            else
            {
                st.push({s[i],1});
            }
        }
        string str = "";
        while(st.size()>0)
        {
            str+=st.top().first;
            st.pop();
        }
        reverse(str.begin(),str.end());
        return str;
    }
};