class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& arr) {
        int n = arr.size();
        stack<int>st;
        vector<int>res(n,-1);
        for(int i=2*n-1;i>=0;i--){
            while(st.size() && st.top()<=arr[i%n]) st.pop();
            if(i<n){
                if(st.size() && st.top()>arr[i])
                res[i] = st.top();
            }
            st.push(arr[i%n]);
        }
        // reverse(res.begin(),res.end());
        // res.resize(n);
        return res;
    }
};