class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int res = 0;
        for(auto it : nums){
            if(it%2==0)
            res+=it;
        }
        vector<int>ans;
        for(auto it : queries){
            if(nums[it[1]]%2==0) res-=nums[it[1]];
            nums[it[1]]+=it[0];
            if(nums[it[1]]%2==0) res+=nums[it[1]];
            ans.push_back(res);
        }
        return ans;
    }
};