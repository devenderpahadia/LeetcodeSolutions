class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) 
    {
        int ctr=0;
        int mx = -1;
        for(auto it : nums)
        {
            if(it==1)
            {
                ctr++;
            }
            else ctr=0;
            mx = max(mx,ctr);
        }
        return mx;
    }
};