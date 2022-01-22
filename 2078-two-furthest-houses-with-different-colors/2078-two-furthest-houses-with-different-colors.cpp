class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int mx = -1;
        for(int i=0;i<colors.size();i++)
        {
            int l=i;
            int h=colors.size()-1;
            while(l<h)
            {
                if(colors[l]!=colors[h])
                {
                    mx = max(mx,h-l);
                    break;
                }
                h--;
            }
        }
        return mx;
    }
};