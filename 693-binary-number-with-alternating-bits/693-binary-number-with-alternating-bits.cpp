class Solution {
public:
    bool hasAlternatingBits(int n) {
        int flag = n%2;
        n/=2;
        while(n)
        {
            if(flag != !(n%2) )
            {
                return false;
            }
            else
            {
                flag = n%2;
                n/=2;
            }
        }
        return true;
    }
};