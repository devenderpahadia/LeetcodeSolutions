class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<pair<int,int>>vec;
        for(int i=0;i<trips.size();i++)
        {
            vec.push_back({trips[i][1],trips[i][0]});
            vec.push_back({trips[i][2],-trips[i][0]});
        }
        
        sort(vec.begin(),vec.end());
        
        int ctr=0;
        for(auto it : vec)
        {
            ctr+=(it.second);
            if(ctr>capacity)
            {
                return false;
            }
        }
        return true;
    }
};