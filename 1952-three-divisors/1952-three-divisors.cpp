class Solution {
public:
    bool isThree(int n) {
        int ctr=2;
        int i=2;
        while(i<=n/2)
        {
            if(n%i == 0)
            {
                ctr++;
            }
            i++;
        }
        return ctr==3;
    }
};