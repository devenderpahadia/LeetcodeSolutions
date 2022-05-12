class Solution {
public:
    void solve(vector<int>&arr)
    {
        int n = arr.size();
        int i=n-1;
        while(i>0){
            if(arr[i-1]<arr[i]) 
                break;
            i--;
        }
        if(i==0){
            reverse(arr.begin(),arr.end());
            return;
        }
        for(int j=n-1;j>=i;j--)
        {
            if(arr[j]>arr[i-1])
            {
                swap(arr[j],arr[i-1]);
                break;
            }
        }
        reverse(arr.begin()+i,arr.end());
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>res;
        // sort(nums.begin(),nums.end());
        vector<int>arr = nums;
        while(1)
        {
            solve(arr);
            res.push_back(arr);
            if(arr==nums)
                break;
        }
        return res;
    }
};