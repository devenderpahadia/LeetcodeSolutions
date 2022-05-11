class Solution {
public:
    
    int Merge(vector < int > & nums, int low, int mid, int high) {
        int total = 0;
        int j = mid + 1;
        for (int i = low; i <= mid; i++) {
            while (j <= high && nums[i] > 2LL * nums[j]) {
                j++;
            }
            total += (j - (mid + 1));
        }

        vector < int > t;
        int left = low, right = mid + 1;

        while (left <= mid && right <= high) {
    
        if (nums[left] <= nums[right]) {
            t.push_back(nums[left++]);
    } else {
      t.push_back(nums[right++]);
    }
  }

  while (left <= mid) {
    t.push_back(nums[left++]);
  }
  while (right <= high) {
    t.push_back(nums[right++]);
  }
  for (int i = low; i <= high; i++) {
    nums[i] = t[i - low];
  }
  return total;
}
    int merge_sort(vector<int>& nums,int l,int r)
    {
        int ctr = 0;
        int mid;
        if(l<r)
        {
            mid = (l+r)/2;
            ctr+=merge_sort(nums,l,mid);
            ctr+=merge_sort(nums,mid+1,r);
            ctr+=Merge(nums,l,mid,r);
        }
        return ctr;
    }
    int reversePairs(vector<int>& nums) {        
        return merge_sort(nums,0,nums.size()-1);
    }
};