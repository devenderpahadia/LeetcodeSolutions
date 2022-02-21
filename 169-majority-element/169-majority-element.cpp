class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cd = nums[0];
        int ctr = 1;
        
        for(int i=1;i<nums.size();i++)
        {
            if(ctr==0)
            {
                cd = nums[i];
            }
            
            if(cd == nums[i])
                ctr++;
            else
                ctr--;
        }
        return cd;
    }
};