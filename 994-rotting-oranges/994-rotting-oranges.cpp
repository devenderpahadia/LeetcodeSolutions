#include<bits/stdc++.h>
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) 
    {
        int time = 0;
        queue<pair<int,int>>q;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({i,j});
                }
            }
        }
        
        while(!q.empty())
        {
            int sz=q.size();
            // bool flag=false;
            while(sz--)
            {
                pair<int,int> temp;
                temp = q.front();
                q.pop();
                int x = temp.first;
                int y = temp.second;
                if(x>0)
                {
                    if(grid[x-1][y]==1)
                    {
                        q.push({x-1,y});
                        grid[x-1][y]=2;
                        // flag=true;
                    }
                }
                if(y>0)
                {
                    if(grid[x][y-1]==1)
                    {
                        q.push({x,y-1});
                        grid[x][y-1]=2;
                        // flag=true;
                    }
                }
                if(x<grid.size()-1)
                {
                    if(grid[x+1][y]==1)
                    {
                        q.push({x+1,y});
                        grid[x+1][y]=2;
                        // flag=true;
                    }
                }
                if(y<grid[0].size()-1)
                {
                    if(grid[x][y+1]==1)
                    {
                        q.push({x,y+1});
                        grid[x][y+1]=2;
                        // flag=true;
                    }
                }
            }
            // if(flag)
                time++;
        }
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1)
                {
                    return -1;
                }
            }
        }
        return time==0 ? 0 :time-1;
    }
};