class Solution {
public:
    int numRescueBoats(vector<int>& nums, int l) {
        sort(nums.begin(),nums.end());
        int i=0;
        int j=nums.size()-1;
        int res = 0;
        while(i<=j)
        {
            res++;
            if(nums[i]+nums[j]<=l)
                i++;
            j--;
        }
        return res;
    }
};