class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>res;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            for(int j = i+1;j<n;j++)
            {
                int x = target - (nums[i] + nums[j]);
                // cout<<x<<endl;
                int l = j+1;
                int h = n-1;
                while(l<h)
                {
                    if(nums[l] + nums[h] < x)
                    {
                        l++;
                    }
                    else if(nums[l] + nums[h] > x)
                    {
                        h--;
                    }
                    else
                    {
                        int p = nums[l];
                        int q = nums[h];
                        res.push_back({nums[i],nums[j],p,q});
                        
                        while(l<h && nums[l]==p) l++;
                        while(l<h && nums[h]==q) h--;
                    }
                }
                while(j+1<n && nums[j+1]==nums[j]) j++;
            }
            while(i+1<n && nums[i+1]==nums[i]) i++;
        }
        return res;
    }
};