class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int l = 0,r = 0,ctr=-1;
        int sum = 0,curr = nums[0];
        int n = nums.size();
        for(auto it : nums){
            if(it==x) return 1;
            sum+=it;
        };
        while(l<n && r<n){
            if(curr<sum-x){
                r++;
                if(r==n) break;
                curr+=nums[r];
            }
            if(curr>sum-x){
                curr-=nums[l];
                l++;
            }
            if(curr==sum-x){
                ctr = max(ctr,r-l+1);
                r++;
                if(r==n) break;
                curr+=nums[r];
            }
        }
        return ctr==-1?-1:n-ctr;
    }
};