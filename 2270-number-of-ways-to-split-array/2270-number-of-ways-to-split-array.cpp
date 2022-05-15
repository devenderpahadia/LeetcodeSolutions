class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long sum = 0;
        int n=nums.size();
        vector<long long>arr(n);
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            arr[i]=sum;
        }
        int ctr=0;
        for(int i=0;i<n-1;i++)
        {
            if(arr[i]>=(arr[n-1]-arr[i])){
                ctr++;
            }
        }
        return ctr;
    }
};