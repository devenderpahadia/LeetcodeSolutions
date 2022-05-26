class Solution {
public:
    int hammingWeight(uint32_t n) 
    {
        int ctr=0;
        for(int i=31;i>=0;i--){
            ctr+=((n>>i)&1);
        }
        return ctr;
    }
};