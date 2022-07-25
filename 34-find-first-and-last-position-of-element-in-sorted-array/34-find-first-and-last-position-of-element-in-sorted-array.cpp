class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int res1 = -1;
        int res2 = -1;
        int n = nums.size();
        int l = 0;
        int h = n-1;
        while(l<=h){
            int mid = l + (h-l)/2;
            if(nums[mid]==target){
                res1 = mid;
                h=mid-1;
            }
            else if(nums[mid]>target){
                h=mid-1;
            }
            else l=mid+1;
        }
        l = 0;
        h = n-1;
        while(l<=h){
            int mid = l + (h-l)/2;
            if(nums[mid]==target){
                res2 = mid;
                l=mid+1;
            }
            else if(nums[mid]>target){
                h=mid-1;
            }
            else l=mid+1;
        }
        return {res1,res2};
    }
};