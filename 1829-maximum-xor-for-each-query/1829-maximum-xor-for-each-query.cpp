class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int xr = 0;
        for(auto it : nums){
            xr=xr^it;
        }
        int sum=0;
        
        for(int i=maximumBit-1;i>=0;i--){
            if((xr>>i & 1) == 0){
                sum+=(1<<i);
            }
        }
        sum = sum^xr;
        vector<int>res;
        xr=0;
        for(auto it : nums){
            xr^=it;
            res.push_back(xr^sum);
        }
        reverse(res.begin(),res.end());
        return res;
    }
};