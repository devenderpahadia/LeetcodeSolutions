class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int n=nums.size();
        int l=0;
        int h=n-1;
        
        while(l<h)
        {
            int mid = l + (h-l)/2;
            if(nums[mid]<nums[h])
                h=mid;
            else
                l=mid+1;
        }
        int index=l;
        
        l=0;
        h=index-1;
        while(l<=h)
        {
            int mid = l + (h-l)/2;
            if(nums[mid]==target)
                return mid;
            else if(nums[mid] < target)
                l=mid+1;
            else
                h=mid-1;
        }
        
        l=index;
        h=n-1;
        
        while(l<=h)
        {
            int mid = l + (h-l)/2;
            if(nums[mid]==target)
                return mid;
            else if(nums[mid]<target)
                l=mid+1;
            else
                h=mid-1;
        }
        return -1;
    }
};