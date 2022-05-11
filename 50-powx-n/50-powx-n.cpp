class Solution {
public:
    double myPow(double x, long n) 
    {
        double ans = 1.0;
        long nn = n;
        if(n<0) nn = (-1)*nn;
        while(nn!=0)
        {
            if(nn%2==0)
            {
                x = x*x;
                nn/=2;
            }
            else
            {
                ans = ans*x;
                nn = (nn-1);
            }
        }
        if(n<0) return (1.0)/(double)ans;
        return ans;
    }
};