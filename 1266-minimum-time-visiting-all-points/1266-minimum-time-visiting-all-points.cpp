class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ctr=0;
        for(int i=0;i<points.size()-1;i++){
            int x = points[i][0];
            int y = points[i][1];
            int x1= points[i+1][0];
            int y1= points[i+1][1];
            ctr+=(max(abs(x1-x),abs(y1-y)));
        }
        return ctr;
    }
};