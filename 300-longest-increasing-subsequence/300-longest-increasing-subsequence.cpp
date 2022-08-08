class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>res;
        res.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            if(nums[i]>res[res.size()-1]){
                res.push_back(nums[i]);
            }
            else{
                int x = lower_bound(res.begin(),res.end(),nums[i])-res.begin();
                res[x] = nums[i];
            }
        }
        return res.size();
    }
};