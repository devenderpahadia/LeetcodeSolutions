class Solution {
public:
    int bitwiseComplement(int num) {
        if(num==0)
            return 1;
        int res = 0;
        int k=0;
        while(num)
        {
            if((num&1)==1)
            {
                num/=2;
            }
            else
            {
                res+=pow(2,k);
                num/=2;
            }
            k++;
        }
        return res;
    }
};