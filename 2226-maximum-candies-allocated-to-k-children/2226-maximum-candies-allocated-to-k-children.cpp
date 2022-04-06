class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
    long long sum = 0;
    for (int c : candies) {
        sum += c;
    }
    if (sum < k) return 0;
     
    int l = 1, r = sum / k + 1;
    while (l + 1 < r) {
        int mid = l + (r - l)/2;
        long long temp = 0;
        for(int c : candies) {
            temp += c / mid;
        }
        if (temp >= k) {
            l = mid;
        } else {
            r = mid;
        }
    }
    return l;
}
};