class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        unordered_map<int,int>mp;
        int res = 0;
        for(int i=0;i<time.size();i++)
        {
            if(mp.find((60-time[i]%60)%60)!=mp.end())
            {
               res+= mp[(60-time[i]%60)%60];
            }
            mp[time[i]%60]++;
        }
        
        return res;
    }
};