class Solution {
public:
    bool isPathCrossing(string path) {
        int i=0,j=0;
        set<pair<int,int>>st;
        st.insert({i,j});
        for(auto it : path)
        {
            if(it=='N')
            {
                i--;
            }
            else if(it=='S')
            {
                i++;
            }
            else if(it=='W')
            {
                j--;
            }
            else if(it=='E')
            {
                j++;
            }
            
            if(st.find({i,j})!=st.end())
            {
                return true;
            }
            st.insert({i,j});
        }
        return false;
    }
};