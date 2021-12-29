class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& inter) {
        sort(inter.begin(),inter.end());
        vector<vector<int>>res;
        res.push_back(inter[0]);
        for(int i=1;i<inter.size();i++)
        {
            if(res[res.size()-1][1] >= inter[i][0])
            {
                res[res.size()-1][1] = max(res[res.size()-1][1],inter[i][1]);
            }
            else
            {
                res.push_back(inter[i]);
            }
        }
        return res;
    }
};