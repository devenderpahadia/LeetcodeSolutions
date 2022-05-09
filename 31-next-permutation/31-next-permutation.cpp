class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n-1;
        while(i>0){
            if(nums[i-1]<nums[i]) break;
            i--;
        }
        if(i==0){
            reverse(nums.begin(),nums.end());
            return;
        }
        for(int j=n-1;j>=i;j--)
        {
            if(nums[j]>nums[i-1]){
                swap(nums[i-1],nums[j]);
                break;
            }
        }
        reverse(nums.begin()+i,nums.end());
    }
};
