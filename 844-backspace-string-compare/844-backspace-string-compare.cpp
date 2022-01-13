class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char>st1;
        stack<char>st2;
        
        for(auto it : s)
        {
            if(st1.empty() && it=='#')
            {
                continue;
            }
            if(it!='#')
            {
                st1.push(it);
            }
            else
                st1.pop();
        }
        for(auto it : t)
        {
            if(st2.empty() && it=='#')
            {
                continue;
            }
            if(it!='#')
            {
                st2.push(it);
            }
            else
                st2.pop();
        }
        
        string s1 = "";
        string s2 = "";
        while(!st1.empty())
        {
            s1+=(st1.top());;
            st1.pop();
        }
        while(!st2.empty())
        {
            s2+=(st2.top());;
            st2.pop();
        }
        return s1==s2;
    }
};