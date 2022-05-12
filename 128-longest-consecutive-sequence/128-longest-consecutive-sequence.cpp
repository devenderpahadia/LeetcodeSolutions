class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        int n = nums.size();
        if(n==0)
            return 0;
        sort(nums.begin(),nums.end());
        int mx =1;
        int end =1;
        int i;
        for(i=1;i<n;i++)
        {
            if(nums[i-1]!=nums[i])
            {
                if(nums[i]-nums[i-1] != 1)
                {
                    mx = max(mx,end);
                    end=1;
                }
                else
                {
                    end++; 
                }
            }
        }
        return max(mx,end);
    }
};