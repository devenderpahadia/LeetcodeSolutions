class Solution {
public:
    int minimumLines(vector<vector<int>>& nums) {
        if(nums.size()<=1) return 0;
        sort(nums.begin(),nums.end());
        int ctr=1;
        long double x1 = (long double)nums[0][0];
        long double y1 = (long double)nums[0][1];
        long double x2 = (long double)nums[1][0];
        long double y2 = (long double)nums[1][1];
        // cout<<(y2-y1)<<endl;
        // cout<<(x2-x1)<<endl;
        long double ma = (long double)((y2-y1)/(x2-x1));
        // cout<<ma<<endl;
        for(int i=2;i<nums.size();i++){
            long double x1 = (long double)nums[i-1][0];
            long double y1 = (long double)nums[i-1][1];
            long double x2 = (long double)nums[i][0];
            long double y2 = (long double)nums[i][1];
            
            long double m = (y2-y1)/(x2-x1);
            // cout<<(y2-y1)<<endl;
            // cout<<(x2-x1)<<endl;
            if(ma!=m){
                ctr++;
                ma = m;
            }
        }
        return ctr;
    }
};