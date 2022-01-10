class MinStack {
public:
    stack<int>st;
    stack<int>sst;
    MinStack() 
    {
        st.push(0);
        st.pop();
    }
    
    void push(int val) {
        st.push(val);
        if(sst.empty()==false)
        {
            if(st.top()<=sst.top())
            {
                sst.push(st.top());
            }
        }
        else
        {
            sst.push(val);
        }
    }
    
    void pop() 
    {
        if(sst.empty()==false && sst.top()==st.top())
        {
            st.pop();
            sst.pop();
        }
        else
        {
            st.pop();
        }
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return sst.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */