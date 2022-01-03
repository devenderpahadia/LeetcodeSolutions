class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>adj[n+1];
        for(auto it : trust)
        {
            adj[it[0]].push_back(it[1]);
        }
        vector<int>res;
        for(int i=1;i<n+1;i++)
        {
            if(adj[i].size()==0)
            {
                res.push_back(i);
            }
        }
        for(int i=0;i<res.size();i++)
        {
            bool flag = true;
            for(int j=1;j<=n;j++)
            {
                if(res[i]!=j)
                {
                    bool temp = false;
                    for(int k=0;k<adj[j].size();k++)
                    {
                        if(adj[j][k] == res[i])
                        {
                            temp = true;
                            break;
                        }
                    }
                    flag = temp;
                    if(!temp)
                        break;
                }
            }
            if(flag)
                return res[i];
        }
        
        return -1;
    }
};
