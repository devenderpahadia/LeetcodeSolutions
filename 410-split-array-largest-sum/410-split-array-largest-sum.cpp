class Solution {
public:
    
    bool check(vector<int>& nums, int x,int m)
    {
        int res = 1;
        int sum = 0;
        
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            if(sum>x)
            {
                res++;
                sum=nums[i];
            }
            if(res>m)
            {
                return false;
            }
        }
        return true;
    }
    
    int splitArray(vector<int>& nums, int m) {
        int l = -1;
        int h = 0;
        for(auto it : nums)
        {
            l=max(l,it);
            h+=it;
        }
        
        while(l<h)
        {
            int mid = l + (h-l)/2;
            if(check(nums,mid,m))
            {
                h=mid;
            }
            else
            {
                l=mid+1;
            }
        }
        return l;
    }
};