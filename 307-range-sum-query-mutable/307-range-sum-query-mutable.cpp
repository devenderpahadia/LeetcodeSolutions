class NumArray {
public:
    vector<int>arr;
    int sum;
    NumArray(vector<int>& nums) {
        arr=nums;
        sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
    }
    
    void update(int index, int val) {
        sum-=arr[index];
        arr[index]=val;
        sum+=val;
    }
    
    int sumRange(int left, int right) {
        int ans = sum;
        for(int i=0;i<left;i++){
            ans-=arr[i];
        }
        for(int i=right+1;i<arr.size();i++){
            ans-=arr[i];
        }
        return ans;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */