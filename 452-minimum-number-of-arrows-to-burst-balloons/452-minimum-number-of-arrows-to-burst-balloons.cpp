class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) 
    {
        sort(points.begin(),points.end());
        int ctr=1;
        int x = points[0][1];
        for(int i=1;i<points.size();i++)
        {
            if(points[i][0]<=x)
            {
                x=min(x,points[i][1]);
                continue;
            }
            x = points[i][1];
            ctr++;
        }
        return ctr;
    }
};