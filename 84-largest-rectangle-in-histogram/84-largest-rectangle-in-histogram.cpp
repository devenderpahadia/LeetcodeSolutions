class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int>st;
        int mx = 0;
        
        for(int i=0;i<=n;i++){
            while(st.size() && ( i==n || heights[st.top()]>=heights[i])){
                int h = heights[st.top()];
                st.pop();
                int w ;
                if(st.size()) w = i-st.top()-1;
                else w = i;
                mx = max(mx,h*w);
            }
            st.push(i);
        }
        return mx;
    }
};