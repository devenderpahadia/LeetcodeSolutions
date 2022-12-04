class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int mx=-1;
        int mn=INT_MAX;
        long long x,y,d;
        
        long long n=nums.size();
        
        vector<long long>t(n,0);
        
        t[0]=nums[0];
        
        for(int i=1;i<n;i++)
            t[i]=t[i-1]+nums[i];
        
        
        for(int i=0;i<n;i++){
            x=t[i];
            y=t[n-1]-t[i];
            d = i==n-1?round(x/(i+1)):abs(round(x/(i+1))-round(y/(n-i-1)));
            if(d<mn)
            {
                mx=i;
                mn=d;
            }
        }
        return mx;
    }
};