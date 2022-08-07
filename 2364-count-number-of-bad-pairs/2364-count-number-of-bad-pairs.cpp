class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long ctr=0;
        long long n = nums.size()-1;
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]-i]++;
        }
        n = n*(n+1)/2;
        for(auto it : mp){
            if((it.second)>1){
                long long t = it.second-1;
                t = t*(t+1)/2;
                ctr+=t;
            }
        }
        return n -ctr;
    }
};