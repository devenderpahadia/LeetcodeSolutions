class Solution {
public:
    int countTriples(int n) {
        int ctr=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(i!=j)
                {
                    int x = i*i + j*j;
                    int y = sqrt(x);
                    if((y*y == x) && y<=n)
                    {
                        ctr++;
                    }
                }
            }
        }
        return ctr;
    }
};