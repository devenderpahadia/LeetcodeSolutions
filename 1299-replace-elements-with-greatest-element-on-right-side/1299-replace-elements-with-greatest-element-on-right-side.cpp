class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int mx=-1;
        vector<int>nums = arr;
        nums[nums.size()-1] = -1;
        for(int i=arr.size()-2;i>=0;i--)
        {
            mx = max(mx,arr[i+1]);
            nums[i] = mx;
        }
        return nums;
    }
};