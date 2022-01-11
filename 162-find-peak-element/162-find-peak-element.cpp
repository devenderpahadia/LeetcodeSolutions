class Solution {
public:
    int findPeakElement(vector<int>& nums) 
    {
        int n = nums.size();
        if(n==1)
            return 0;
        int l=0;
        int h=n-1;
        int mid;
        
        while(l<=h)
        {
            mid = l + (h-l)/2 ;
            if(mid>0 && mid<n-1)
            {
                if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1])
                {
                    return mid;
                }
                else if(nums[mid-1]>nums[mid])
                {
                    h=mid-1;
                }
                else if(nums[mid+1]>nums[mid])
                {
                    l=mid+1;
                }
            }
            else if(mid==0)
            {
                if(nums[0]>nums[1])
                {
                    return 0;
                }
                else
                {
                    return 1;
                }
            }
            else if(mid==n-1)
            {
                if(nums[n-1] > nums[n-2] )
                {
                    return n-1;
                }
                else
                {
                    return n-2;
                }
            }
        }
        
        return 0;
    }
};