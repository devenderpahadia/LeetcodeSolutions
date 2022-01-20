class Solution {
public:
    bool judgeCircle(string moves) {
        int i=0,j=0;
        for(auto it : moves)
        {
            if(it=='U')
            {
                i--;
            }
            else if(it=='D')
            {
                i++;
            }
            else if(it=='L')
            {
                j--;
            }
            else if(it=='R')
            {
                j++;
            }
        }
        return (i==0 && j==0);
    }
};