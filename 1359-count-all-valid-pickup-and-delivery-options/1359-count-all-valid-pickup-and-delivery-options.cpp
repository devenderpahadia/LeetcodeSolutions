class Solution {
public:
    int countOrders(int n) {
        int m = n;
        long long res = 1;
        int mod = pow(10,9)+7;
        
        while(m)
        {
            res*=m;
            m--;
            res%=mod;
        }
        
        int x = 1;
        while((2*n - x)>0)
        {
            res*=(2*n-x);
            x+=2;
            res%=mod;
        }
        return res;
    }
};