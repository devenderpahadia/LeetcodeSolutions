class Solution {
public:
    int arraySign(vector<int>& nums) {
        int ctr=0;
        for(auto it : nums)
        {
            if(it==0)
                return 0;
            
            if(it<0)
                ctr++;
        }
        if(ctr%2==0)
        {
            return 1;
        }
        return -1;
    }
};