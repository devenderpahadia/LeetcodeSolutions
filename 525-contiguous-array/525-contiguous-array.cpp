class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> m;
        int ans = 0;
        int sum = 0;
        m[0] = -1;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i] == 0 ? -1 : 1;
            if (m.find(sum) == m.end()){
                m[sum] = i;
            }
            else{
                ans = max(ans, i - m[sum]);
            }
        }
        return ans;
    }
};