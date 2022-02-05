class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        if(nums.size()==1)
            return 0;
        vector<int>vec = nums;
        sort(nums.begin(),nums.end());
        
        if(nums[nums.size()-2]*2 <=nums[nums.size()-1])
        {
            for(int i=0;i<vec.size();i++)
            {
                if(vec[i]==nums[nums.size()-1])
                    return i;
            }
        }
        return -1;
    }
};