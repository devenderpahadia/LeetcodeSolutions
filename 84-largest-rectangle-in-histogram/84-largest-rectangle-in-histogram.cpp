class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<pair<int,int>>st;
        
        vector<int>nsl(n,0);
        vector<int>nsr(n,0);
        for(int i=0;i<n;i++){
            while(st.size() && st.top().first>=heights[i]) st.pop();
            if(st.size()) nsl[i] = st.top().second+1;
            else nsl[i] = 0;
            
            st.push({heights[i],i});
        }
        while(!st.empty()) st.pop();
        for(int i=n-1;i>=0;i--){
            while(st.size() && st.top().first>=heights[i]) st.pop();
            if(st.size()) nsr[i] = st.top().second-1;
            else nsr[i] = n-1;
            
            st.push({heights[i],i});
        }
        int mx = -1;
        for(int i=0;i<n;i++){
            mx = max(mx, (nsr[i]-nsl[i]+1)*heights[i]);
        }
        return mx;
    }
};