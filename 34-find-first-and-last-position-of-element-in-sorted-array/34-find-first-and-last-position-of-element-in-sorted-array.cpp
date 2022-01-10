class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        int first=-1;
        int second=-1;
        int l=0;
        int h=nums.size()-1;
        int mid;
        
        while(l<=h)
        {
            mid= l+(h-l)/2;
            if(nums[mid]==target)
            {
                first=mid;
                h=mid-1;
            }
            else if(target<nums[mid])
            {
                h=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        l=0;
        h=nums.size()-1;
        while(l<=h)
        {
            mid= l+(h-l)/2;
            if(nums[mid]==target)
            {
                second=mid;
                l=mid+1;;
            }
            else if(target<nums[mid])
            {
                h=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        //cout<<first<<" "<<second<<endl;
        vector<int>res;
        if(first==-1 || second==-1)
        {
            res.push_back(-1);
            res.push_back(-1);
            return res;
        }
        else
        {
            res.push_back(first);
            res.push_back(second);
            return res;
        }
        
    }
};