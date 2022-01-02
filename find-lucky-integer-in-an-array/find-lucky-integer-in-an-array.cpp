class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int>mp;
        for(auto it : arr)
        {
            mp[it]++;
        }
        int mx = -1;
        
        for(auto it : mp)
        {
            if(it.first == it.second)
            {
                mx = max(mx,it.first);
            }
        }
        return mx;
    }
};