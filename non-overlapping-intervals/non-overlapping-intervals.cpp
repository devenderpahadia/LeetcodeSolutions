class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& I) {
        int n = I.size(), count=0;
        if(n<=1) return count;
        sort(I.begin(), I.end());
        for(int i=0; i<n; i++) {
            int end = I[i][1];
            while(i+1<n && I[i+1][0]<end) {
                count++;
                end = min(end, I[i+1][1]);
                i++;
            }
        }
        return count;
    }
};