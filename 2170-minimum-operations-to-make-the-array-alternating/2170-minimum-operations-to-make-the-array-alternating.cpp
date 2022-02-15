class Solution {
public:
    array<int, 3> top2Freq(vector<int>& nums, int start) {
    int first = 0, second = 0, cnt[100001] = {};
    for (int i = start; i < nums.size(); i += 2)
        if (++cnt[nums[i]] >= cnt[first]) {
            if (nums[i] != first)
                second = first;    
            first = nums[i];
        }
        else if (cnt[nums[i]] > cnt[second])
            second = nums[i];
    return {first, cnt[first], cnt[second]};
}
int minimumOperations(vector<int>& nums) {
    auto ev = top2Freq(nums, 0), od = top2Freq(nums, 1);
    return nums.size() - (ev[0] != od[0] ? ev[1] + od[1] : max(ev[1] + od[2], ev[2] + od[1]));
}
};
