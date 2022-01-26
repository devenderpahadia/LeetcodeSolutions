class Solution {
public:
    int minOperations(vector<int>& nums) {
        if(nums.size()==1)
            return 0;
        int i;
        for(i=1;i<nums.size();i++)
        {
            if(nums[i-1]>=nums[i])
            {
                break;
            }
        }
        if(i==nums.size())
        {
            return 0;
        }
        int flag=0;
        int ctr=0;
        for(;i<nums.size();i++)
        {
            if(nums[i-1]>=nums[i])
            {
                ctr+=(nums[i-1]-nums[i])+1;
                nums[i]+= (nums[i-1]-nums[i])+1;
            }
        }
        return ctr;
    }
};