class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        
        if(nums.size()==1)
        {
            if(k%2==1)
                return -1;
            else
                nums[0];
        }
        if(k>nums.size())
        {
            return *max_element(nums.begin(),nums.end());
        }
        else
        {
            int mx = -1;
            for(int i=0;i<k-1;i++)
            {
                mx = max(mx,nums[i]);
            }
            return max(mx,nums[k]);
        }
        
    }
};