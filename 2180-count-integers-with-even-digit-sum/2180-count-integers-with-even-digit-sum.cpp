class Solution {
public:
    bool solve(int n)
    {
        int sum=0;
        while(n)
        {
            sum+=(n%10);
            n/=10;
        }
        return sum%2==0;
    }
    int countEven(int num) {
        int ctr=0;
        while(num)
        {
            if(solve(num))
                ctr++;
            num--;
        }
        return ctr;
    }
};