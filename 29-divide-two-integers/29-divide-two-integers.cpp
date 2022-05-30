class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == INT_MIN && divisor==-1)
            return INT_MAX;
        if(dividend == INT_MIN && divisor==1)
            return INT_MIN;
        
        
        int flag = 0;
        if(dividend<0 && divisor<0) flag=0;
        else if(dividend<0 || divisor<0) flag = 1;
        
        long int dd = abs(dividend);
        long int dv = abs(divisor);
        int ctr=0;
        
        while(dd>=dv){
            long int mul = dv;
            long int temp = 1;
            while(mul<=dd-mul){
                mul+=mul;
                temp+=temp;
            }
            ctr+=temp;
            dd-=mul;
        }
        if(flag){
            ctr = -ctr;
        }
        return ctr;
    }
};