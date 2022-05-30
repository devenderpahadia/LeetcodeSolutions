class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& arr) {
        int n = arr.size();
        stack<int>st;
        vector<int>res;
        for(int i=2*n-1;i>=0;i--){
            while(st.size() && st.top()<=arr[i%n]) st.pop();
            if(st.empty()) res.push_back(-1);
            if(st.size() && st.top()>arr[i%n]) res.push_back(st.top());
            st.push(arr[i%n]);
        }
        reverse(res.begin(),res.end());
        res.resize(n);
        return res;
    }
};