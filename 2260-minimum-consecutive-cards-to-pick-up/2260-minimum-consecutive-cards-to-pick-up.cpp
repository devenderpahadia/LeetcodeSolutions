class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        unordered_map<int,int>mp;
        int mn = INT_MAX;
        for(int i=0;i<cards.size();i++)
        {
            if(mp.find(cards[i])!=mp.end())
            {
                mn = min(mn,i-mp[cards[i]]+1);
            }
            mp[cards[i]] = i;
        }
        if(mn==INT_MAX)
            return -1;
        return mn;
    }
};