class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int med;
        if(nums.size()%2==0){
            med = nums[nums.size()/2 -1] + nums[nums.size()/2];
            med/=2;
        }
        else{
            // cout<<"dev"<<endl;
            med = nums[nums.size()/2];
        }
        int sum = 0;
        for(auto it : nums){
            sum+=(abs(med-it));
        }
        // cout<<med<<endl;
        return sum;
    }
};