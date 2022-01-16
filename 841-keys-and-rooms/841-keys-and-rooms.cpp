class Solution {
public:
    
    void solve(int i,vector<vector<int>>& rooms,vector<int>&vis)
    {
        vis[i]=1;
        for(int j=0;j<rooms[i].size();j++)
        {
            if(vis[rooms[i][j]]==0)
            {
                solve(rooms[i][j],rooms,vis);
            }
        }
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int>vis(n,0);
        
        solve(0,rooms,vis);
        for(auto it : vis)
        {
            if(it==0)
            {
                return false;
            }
        }
        return true;
    }
};