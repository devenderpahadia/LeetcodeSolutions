class Solution {
public:
    
    bool solve(vector<int>& nums,int W){
        int n = nums.size();
        bool t[n+1][W+1];
        
        for(int i=1;i<=W;i++) t[0][i] = false;
        for(int i=0;i<=n;i++) t[i][0] = true;
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=W;j++){
                if(nums[i-1]<=j){
                    t[i][j] = t[i-1][j] || t[i-1][j-nums[i-1]];
                }
                else t[i][j] = t[i-1][j];
            }
        }
        return t[n][W];
    }
    
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto it : nums) sum+=it;
        
        if(sum%2==1) return false;
        
        return solve(nums,sum/2);
    }
};