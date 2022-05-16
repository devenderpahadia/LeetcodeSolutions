class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>res;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        if(n<3)
            return res;
        for(int i=0;i<nums.size()-2;i++){
            if(i>0 && nums[i-1]==nums[i]) continue;
            int sum = 0-nums[i];
            int l = i+1;
            int h = n-1;
            while(l<h){
                if(nums[l]+nums[h]<sum) l++;
                else if(nums[l]+nums[h]>sum) h--;
                else{
                    int p = nums[l];
                    int q = nums[h];
                    res.push_back({nums[i],p,q});
                    while(l<h && nums[l]==p) l++;
                    while(l<h && nums[h]==q) h--;
                }
            }
        }
        return res;
    }
};