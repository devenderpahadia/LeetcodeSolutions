class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        vector<int>vec = nums;
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]>nums[i]){
                nums[i-1]=nums[i];
                break;
            }
        }
        // for(auto it : nums) cout<<it<<" ";
        int flag = 1;
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]>nums[i]){
                flag = 0;
                break;
            }
        }
        if(flag) return true;
        nums=vec;
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]>nums[i]){
                nums[i]=nums[i-1];
                break;
            }
        }
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]>nums[i]){
                return false;
            }
        }
        return true;
    }
};