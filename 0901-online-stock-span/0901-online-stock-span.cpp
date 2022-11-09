class StockSpanner {
public:
    stack<pair<int,int>>st;
    StockSpanner() {
    }
    int next(int price) {
        pair<int,int>temp;
        temp.first = price;
        temp.second = 1;
        while(st.size() && st.top().first<=price){
            temp.second+=st.top().second;
            st.pop();
        } 
        st.push(temp);
        return st.top().second;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */