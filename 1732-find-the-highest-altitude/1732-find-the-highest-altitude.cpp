class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int x = 0;
        int mx = -1;
        for(auto it : gain)
        {
            mx = max(mx,x);
            x+=it;
        }
        mx = max(mx,x);
        return mx;
    }
};