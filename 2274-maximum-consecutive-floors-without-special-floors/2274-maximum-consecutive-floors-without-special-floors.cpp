class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        sort(special.begin(),special.end());
        int mx = 0;
        int x = bottom;
        for(int i=0;i<special.size();i++)
        {
            mx = max(mx,special[i]-x);
            x = special[i]+1;
        }
        x=top;
        for(int i=special.size()-1;i>=0;i--)
        {
            mx = max(mx,x- special[i]);
            x=special[i]-1;
        }
        return mx;
    }
};