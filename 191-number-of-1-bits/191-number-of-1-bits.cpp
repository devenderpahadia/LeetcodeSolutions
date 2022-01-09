class Solution {
public:
    int hammingWeight(uint32_t n) 
    {
        int ctr=0;
        while(n!=0)
        {
            ctr+= (n%2);
            n=n/2;
        }
        return ctr;
    }
};