class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int>st;
        int j=0;
        st.push(pushed[0]);
        for(int i=1;i<pushed.size();)
        {
            if(st.size() && st.top()==popped[j])
            {
                cout<<st.top()<<endl;
                st.pop();
                j++;
            }
            else
            {
                st.push(pushed[i]);
                i++;
            }
        }
        while(st.size())
        {
            if(st.top()==popped[j])
            {
                cout<<st.top()<<endl;
                st.pop();
                j++;
            }
            else
                return false;
        }
        return true;
    }
};