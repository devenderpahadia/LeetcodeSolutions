class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int>vec(n,0);
        int mx = 1;
        vec[0]=1;
        for(int i=1;i<vec.size();i++)
        {
            if(nums[i-1]<nums[i])
            {
                vec[i]=1+vec[i-1];
            }
            else
            {
                vec[i]=1;
            }
            mx = max(mx,vec[i]);
        }
        return mx;
    }
};