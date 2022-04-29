class Solution {
public:
    
    bool solve(int x,int y,int x1,int y1,int r)
    {
        return (x-x1)*(x-x1) + (y-y1)*(y-y1) <= r*r;
    }
    
    int countLatticePoints(vector<vector<int>>& circles) {
        set<pair<int,int>>st;
        for(auto it : circles)
        {
            int x = it[0];
            int y = it[1];
            int r = it[2];
            for(int i=x-r;i<=x+r;i++)
            {
                for(int j=y-r;j<=y+r;j++)
                {
                    if(solve(i,j,x,y,r))
                        st.insert({i,j});
                }
            }
        }
        
        return st.size();
    }
};