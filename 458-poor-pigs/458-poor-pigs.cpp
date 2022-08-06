class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int t = minutesToTest/minutesToDie+1;
        int res = 0;
        while(pow(t,res)<buckets) res++;
        return res;
    }
};
