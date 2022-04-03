class Solution {
public:
    void nextPermutation(vector<int>& nums) 
    {
        int i;
        int n=nums.size();
        
        for(i=n-1;i>0;i--)
        {
            if(nums[i-1]<nums[i])
            {
                break;
            }
        }
        if(i==0)
        {
            sort(nums.begin(),nums.end());
            return;
        }
        for(int j=n-1;j>=i;j--)
        {
            if(nums[i-1]<nums[j])
            {
                swap(nums[i-1],nums[j]);
                break;
            }
        }
        reverse(nums.begin()+i,nums.end());
        
    }
};
