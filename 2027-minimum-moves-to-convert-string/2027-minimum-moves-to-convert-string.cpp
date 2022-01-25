class Solution {
public:
    int minimumMoves(string s) {
        int ctr=0;
        for(int i=0;i<s.size();)
        {
            if(s[i]=='X')
            {
                ctr++;
                i+=3;
            }
            else
            {
                i++;
            }
        }
        return ctr;
    }
};