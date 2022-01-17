class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);   
        for (int i = 0, lsum = 0; i < nums.size(); ++i) {
            if (lsum == sum - nums[i] - lsum) return i;
            else {
                lsum += nums[i];
            }
        }
        return -1;
    }
};