class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        
        long long n = num/3;
        
        if((n)+(n+1)+(n+2) == num)
            return {n,n+1,n+2};
        if((n-1)+(n)+(n+1) == num)
            return {n-1,n,n+1};
        if((n-2)+(n-1)+(n) == num)
            return {n-2,n-1,n};
        
        return {};
    }
};