class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int>res = nums;
        sort(res.begin(),res.end());
        int i;
        for(i=0;i<nums.size();i++)
        {
            if(nums[i]!=res[i])
            {
                break;
            }
        }
        if(i==nums.size())
            return 0;
        int j;
        for(j=nums.size()-1;j>=0;j--)
        {
            if(nums[j]!=res[j])
            {
                break;
            }
        }
        if(j==0)
            return 0;
        return j-i+1;
    }
};